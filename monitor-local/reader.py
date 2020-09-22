import csv
import json
import time
import socket
from time import sleep
from csv_vars import OpcCsv
from opc import OpcServer
from multiprocessing import Process, Queue

current_milli_time = lambda: int(round(time.time() * 1000))

class Reader(Process): 

    def  __init__(self, periodic_time, plc_scan_cycle, q_in, q_out, opc_server, log_queue):
        super(Reader, self).__init__() 
        self.q_in = q_in
        self.q_out = q_out
        self.opc_conn = opc_server
        self.periodic_time = periodic_time
        self.log_queue = log_queue
        self.plc_scan_cycle = plc_scan_cycle
        print("---Reader Created")

    def log(self, level, msg):
        self.log_queue.put((level, 'READER', msg))
        
    def run(self):
        print("---Reader Started") 

        # Read CSV
        csv = OpcCsv()
        variables = csv.list_variables()
        input_variables = csv.list_variables('INPUT')
        reset_variables = csv.list_variables('RESET')
        output_variables = csv.list_variables('OUTPUT')

        # Opc connection
        opc = OpcServer(self.opc_conn)
        opc.create_group(variables, 'reader')
        opc.create_group(input_variables + reset_variables, 'input')
        opc.create_group(output_variables, 'output')
        values = opc.read_group('reader', self.opc_conn)

        while True:
            start_time = current_milli_time()
            # Store PLC Inputs
            table_in = opc.read_group('input', self.opc_conn)            
            #sleep(self.plc_scan_cycle)
            # Store PLC Outputs
            table_out = opc.read_group('output', self.opc_conn) 
            
            # Send to buffer
            values = {}
            for v in table_in:
                values[v[0]] = v[1]
            self.q_in.put(values)
            values = {}
            for v in table_out:
                values[v[0]] = v[1]
            self.q_out.put(values)

            end_time = current_milli_time()
            delta = (end_time - start_time)/1000.0

            if delta > self.periodic_time:
                self.log(4, "READER:: DEADLINE PASSED {}".format(delta))
            else:
                start_sleep_time = current_milli_time()
                sleep(self.periodic_time - delta)
                end_sleep_time = current_milli_time()
                delta_over = (end_sleep_time - start_sleep_time) / 1000.0
                self.log(0, "READER::OK {} / {}".format(delta, self.periodic_time - delta))
                self.log(0, "Reader Over {}".format(delta_over))
                