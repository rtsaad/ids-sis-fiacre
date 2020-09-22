import csv
import json
import time
import random
import socket
from time import sleep
from opc import OpcServer
from csv_vars import OpcCsv
from multiprocessing import Process

current_milli_time = lambda: int(round(time.time() * 1000))

OPC_SERVER = 'CoDeSys.OPC.DA'
OPC_SERVER_ADDRESS = 'localhost'
OPC_VARIABLES_PATH = 'PLC01.Application.IOCONFIG_GLOBALS_MAPPING'

class Writer(Process): 

    def  __init__(self, periodic_time, log_queue):
        super(Writer, self).__init__() 
        self.periodic_time = periodic_time
        self.log_queue = log_queue
        print("--Writer Created")

    def log(self, level, msg):
        self.log_queue.put((level, 'WRITER', msg))

    def run(self): 

        print("--Writer Started")

        opc = OpcServer(OPC_SERVER, address=OPC_SERVER_ADDRESS)
        opc_vars = OpcCsv()
        input_variables = opc_vars.list_variables('INPUT')
        output_variables = opc_vars.list_variables('OUTPUT')
        opc.create_group(input_variables, 'INPUT')
        opc.create_group(output_variables, 'OUTPUT')

        outputs = []            # Register output variables at opc serve 
        write_off = []
        for inp in opc_vars.OPC_VARIABLES_LIST:
            direction = inp[3]
            if direction == 'OUTPUT':
                value = opc_vars.release_value(inp)
                outputs.append((inp[0] + '.' + inp[1], value))
                continue
            elif direction == 'RESET':
                continue
            # Only for inputs
            value = opc_vars.release_value(inp)
            write_off.append((inp[0] + '.' + inp[1], value))

        opc.write_batch(outputs)
        reset_list = ([], [])
        for inp in opc_vars.OPC_VARIABLES_LIST:
            direction = inp[3]
            if direction == 'RESET':
                reset_list[0].append((inp[0] + '.' + inp[1], 1))
                reset_list[1].append((inp[0] + '.' + inp[1], 0))
        while True:
            tics = 18
            while True:
                # Write random inputs every X tics
                if tics > 12:
                    # Check for Reset Variables
                    if len(reset_list[0]) > 0:
                        self.log(0, "RESET variables Start")
                        # Reset variables
                        # print(opc_write_batch(reset_list[0]))
                        opc.write_batch(write_off + reset_list[0])
                        time.sleep(6)
                        # Release Variables
                        #print(opc_write_batch(reset_list[1]))
                        #time.sleep(2)
                        self.log(0, "RESET variables End")

                    self.log(0,"Write Random Inputs")
                    write_values = None # [27000, 27000, 27000, 27000, 27000, 27000, 27000, 7000, 12000, 12000, 12000, 12000, 12000, 6000, 6000, 6000, 6000, 6000, 6000, 6000, 6000, 6000, 6000, 7000, 7000, 7000, 7000, 1, 1]
                    write = [] + reset_list[1]
                    if not write_values:
                        for inp in opc_vars.OPC_VARIABLES_LIST:
                            direction = inp[3]
                            if direction == 'OUTPUT' or direction ==  'RESET':
                                continue
                            # Only for inputss
                            ttype = inp[2]
                            if ttype == 'DIGITAL':
                                value = random.choice([True, False])
                                write.append((inp[0] + '.' + inp[1], value))
                            else:
                                value = opc_vars.force_value(random.choice(opc_vars.get_levels(inp)), inp)
                                write.append((inp[0]+ '.' + inp[1], value))
                    else:
                        for inp, value in zip(opc_vars.OPC_VARIABLES_LIST, write_values):
                            direction = inp[3]
                            if direction == 'OUTPUT' or direction == 'RESET':
                                continue
                            write.append((inp[0] + '.' + inp[1], value))

                    opc.write_batch(write)
                    tics = 0
                tics = tics + 1
                # Read OPc variables
                self.log(0,"Sleeping...")
                time.sleep(2)