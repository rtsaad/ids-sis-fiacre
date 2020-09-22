
import json
import argparse
from datetime import datetime
from time import sleep
import time
from multiprocessing import Process, Queue, Manager
import sys
import random
from csv_vars import OpcCsv
from opc import OpcServer
from plc import Plc
from logger import Logger
from fiacre import Fiacre
from reader import Reader
from writer import Writer

current_milli_time = lambda: int(round(time.time() * 1000))

# Constants
# Ignore command line arguments to set the values directly here
IGNORE_COMMAND_ARGUMENTS = True
# Default values
PERIODIC_TIME = 0.125
PLC_SCAN_CYCLE = 0.050
VERBOSE = 3
SLIDING_WINDOW = 3


def main(): 

    # Set arguments
    if IGNORE_COMMAND_ARGUMENTS:
        peridic_time_value  = PERIODIC_TIME
        scan_cycle_value    = PLC_SCAN_CYCLE
        verbose_value       = VERBOSE
        sliding_window_value= SLIDING_WINDOW
    else:
        parser = argparse.ArgumentParser()
        parser.add_argument('-pt','--periodic_time', help='Set the periodic constraint to be respected by all processors.', default=PERIODIC_TIME)
        parser.add_argument('-sc','--scan_cycle', help='PLC scan cycle constraint.', default=PLC_SCAN_CYCLE)
        parser.add_argument('-sw','--sliding_window', help='Number of sliding windows.', default=SLIDING_WINDOW)
        parser.add_argument('-v', '--verbose', help='Print debug logs')
        args = parser.parse_args()
        verbose_value = VERBOSE
        if(args.verbose):
            verbose_value = 1
        peridic_time_value  = args.periodic_time
        scan_cycle_value    = args.scan_cycle
        sliding_window_value = args.sliding_window

    # Start Process
    with Manager() as manager: 

        # Communication channels
        log_channel = Queue()
        q_in = Queue() 
        q_out = Queue()
        opc_conn = manager.dict()

        # Start logger
        logger = Logger(log_channel, verbose_value)
        logger.start()

        # System                
        # Process to simulate the inputs
        writer = Writer(peridic_time_value, opc_conn, log_channel)
        writer.start()
        sleep(3)    
        # Process to emulate the sis (pcl)
        sis = Plc(scan_cycle_value, opc_conn, log_channel)
        sis.start()       
        sleep(1)

        # Monitor
        # Process to read the inputs and outputs from the SIS(PLC) and forward 
        # to VSIS
        reader = Reader(peridic_time_value, scan_cycle_value, q_in, q_out, opc_conn, log_channel)
        reader.start()
        # Process to etablish a socket communication with VSIS (FIACRE-HIPPO) 
        # and to compare if their output matches. 
        vsis = Fiacre(peridic_time_value, sliding_window_value, q_in, q_out, log_channel)        
        vsis.start()

        # Never stops, must be halted by the user.
        logger.join()
        writer.join()
        sis.join()
        reader.join()
        vsis.join()


if __name__ == "__main__":
    main()
