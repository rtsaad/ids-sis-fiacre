import csv
import random
from time import sleep
from csv_vars import OpcCsv

class OpcServer: 
    
    # Max Latency in ms
    LATENCY_WRITE = 1
    LATENCY_READ = 1

    def  __init__(self, table):
        self.init()
        self.groups = {} 

    def init(self):
        self.opc_csv = OpcCsv()

    def latency(self, latency_time):
        sleep_time = (random.randint(0, latency_time) / (1000.0))
        sleep(sleep_time)

    def list_variables(self, table):
        return table.values()

    def list_variables_names(self, table):
        return table.keys()

    def create_group(self, variables, group_name):
        self.groups[group_name] = variables

    def read_group(self, group_name, table):
        self.latency(self.LATENCY_READ)
        ll = []
        for v in self.groups[group_name]:
            ll.append(table[v])
        return ll

    def write_batch(self, batch, table):
        self.latency(self.LATENCY_WRITE)
        for v in batch:
            table[v[0]] = v 
        return table