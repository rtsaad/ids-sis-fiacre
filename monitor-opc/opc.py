import OpenOPC
import csv
import random
from time import sleep
from csv_vars import OpcCsv

class OpcServer: 
    
    # Max Latency in ms
    LATENCY_WRITE = 1
    LATENCY_READ = 1
    opc = None

    def  __init__(self, server, address='localhost'):
        self.init(server, address)

    def init(self, server, address='localhost'):
        self.opc_csv = OpcCsv()
        self.opc = OpenOPC.open_client(address)
        self.opc.connect(server)

    def list_variables(self, path):
        return  self.opc.list(path, recursive=True)

    def create_group(self, variables, group_name):
        self.opc.read(variables, group=group_name)

    def read_group(self, group_name):
        return self.opc.read(group=group_name)

    def read(self, var_name):
        return self.opc.read(var_name)

    def write_batch(self, batch):
        self.opc.write(batch)