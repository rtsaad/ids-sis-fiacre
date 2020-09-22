import csv
import json
import time
import socket
from time import sleep
from csv_vars import OpcCsv
from multiprocessing import Process, Queue


current_milli_time = lambda: int(round(time.time() * 1000))

class Fiacre(Process): 

    SOCKET_SERVER_ADDRESS = ''
    SOCKET_SERVER_PORT = 5000

    def  __init__(self, periodic_time, windows, q_in, q_out, log_queue):
        super(Fiacre, self).__init__() 
        self.q_in = q_in
        self.q_out = q_out
        self.periodic_time = periodic_time
        self.windows = windows
        self.log_queue = log_queue
        print("----Monitor Created")

    def log(self, level, msg):
        self.log_queue.put((level, 'FIACRE', msg))

    def socket_connect(self): 
        self.TCP = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        orig = (self.SOCKET_SERVER_ADDRESS, self.SOCKET_SERVER_PORT)
        self.TCP.bind(orig)

    def socket_listen(self, value=1):
        self.TCP.listen(value)

    def run(self):
        
        print("----Monitor started")
        print("----You can now start VSIS (Fiacre/Hippo) executable")
        
        last_js = None
        last_last_js = None
        last_last_last_js = None
        last_last_last_last_js = None
        # Read CSV
        csv = OpcCsv()
        input_variables = csv.list_variables('INPUT')
        reset_variables = csv.list_variables('RESET')
        output_variables = csv.list_variables('OUTPUT')

        # Logs
        errors = open('errors.txt', 'w', buffering=256)

        # Start Socket Server
        self.socket_connect()
        self.socket_listen()
        con, client = self.TCP.accept()
        last_time = current_milli_time()
        while True:
            start_time = current_milli_time()
            elapsed = (last_time - start_time) / 1000.0
            self.log(0, "Monitor Elapsed {}".format(elapsed))
            inputs = []
            outputs = []
            table = self.q_in.get()
            for inp in input_variables:
                inputs.append(table[inp])
            for inp in reset_variables:
                inputs.append(1 if (table[inp]) else 0)
            table = self.q_out.get()
            for output in output_variables:
                outputs.append(table[output])
            # Send
            send = {
                'at': inputs
            }
            # TODO: 
            # Python 2 send a string over the socket, remove "encode()" call below
            # uncomment the line below to use with Python2
            con.send(json.dumps(send))
            # Python 3 send a byte object over the socket
            # uncomment the line below to use with Python3
            # con.send(json.dumps(send).encode())
            # Read data output through socket
            msg = con.recv(4096)
            if msg:
                js = json.loads(msg)
                # Compare values with Emulator
                ok = True
                for i in range(0, len(output_variables)):
                    if self.windows == 0 and outputs[i] != js['at'][i]:
                        ok = False
                    elif self.windows == 1 and outputs[i] != js['at'][i]  and \
                            (last_js and outputs[i] != last_js['at'][i]):
                        ok = False
                    elif self.windows == 2 and outputs[i] != js['at'][i]  and \
                            (last_js and outputs[i] != last_js['at'][i]) and \
                            (last_last_js and outputs[i] != last_last_js['at'][i]):
                        ok = False
                    elif self.windows == 3 and outputs[i] != js['at'][i]  and \
                            (last_js and outputs[i] != last_js['at'][i]) and \
                            (last_last_js and outputs[i] != last_last_js['at'][i]) and \
                            (last_last_last_js and outputs[i] != last_last_last_js['at'][i]):
                        ok = False
                    elif self.windows == 4 and outputs[i] != js['at'][i]  and \
                            (last_js and outputs[i] != last_js['at'][i]) and \
                            (last_last_js and outputs[i] != last_last_js['at'][i]) and \
                            (last_last_last_js and outputs[i] != last_last_last_js['at'][i]) and\
                            (last_last_last_last_js and outputs[i] != last_last_last_last_js['at'][i]):
                        ok = False
                if ok:
                    self.log(1, "Monitor OK")
                else:
                    self.log(4, 'Monitor NOK')
                    self.log(4, "--INPUTS")
                    self.log(4, " ".join(str(x) for x in inputs))
                    self.log(4, "--PLC OUTPUTS")
                    self.log(4, " ".join(str(x) for x in outputs))
                    self.log(4, '--FIACRE OUTPUTS')
                    self.log(4, " ".join(str(x) for x in js))
                    errors.write("#############################################################################\n")
                    errors.write("{} \n {}\n {}\n".format(inputs, outputs, json.dumps(js)))
                    errors.write("\n \n")
                
                last_last_last_js = last_last_js
                last_last_js = last_js
                last_js = js
            else:
                self.log(5, "Failed to receive data from model")
            end_time = current_milli_time()
            delta = (end_time - start_time) / 1000.0
            if (delta > self.periodic_time):
                self.log(5, "MONITOR::::DEADLINE PASSED {}".format(delta))
            else:
                start_sleep_time = current_milli_time()
                sleep(self.periodic_time - delta)
                end_sleep_time = current_milli_time()
                delta_over = (end_sleep_time - start_sleep_time) / 1000.0
                self.log(0, "Monitor::OK {}".format(delta))
                self.log(0, "Monitor Over {}".format(delta_over))
            last_time = current_milli_time()
        self.log(0, 'Closing connection with client')
        con.close()
        errors.close()

