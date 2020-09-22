import csv
import json
import time
import socket
from time import sleep
from csv_vars import OpcCsv
from opc import OpcServer
from multiprocessing import Process, Queue

current_milli_time = lambda: int(round(time.time() * 1000))

# Local defs
def v1oo4(A, B, C, D):
    Q = False
    Q = A or B or C or D
    return Q
    
def v1oo7(A, B, C, D, E, F, G):
    Q = False
    Q = A or B or C or D or E or F or G
    return Q
    
def v1oo10(A, B, C, D, E, F, G, H, I, J):
    Q = False
    Q = A or B or C or D or E or F or G or H or I or J
    return Q

def v2oo3(A, B, C):
    Q = False
    Q = (A and B) or (B and C) or (A and C)
    return Q

def v2oo4(I1, I2, I3, I4):
    Q = False
    Q = (I1 and I2) or (I1 and I3) or (I1 and I4) \
        or (I2 and I3) or (I2 and I4) \
        or (I3 and I4) 
    return Q
    

def v2oo5(I1, I2, I3, I4, I5):
    Q = False
    Q = (I1 and I2) or (I1 and I3) or (I1 and I4) or (I1 and I5) \
        or (I2 and I3) or (I2 and I4) or (I2 and I5) \
        or (I3 and I4) or (I3 and I5) \
        or (I4 and I5)
    return Q
    

def v2oo7(I1, I2, I3, I4, I5, I6, I7):
    Q = False
    Q = (I1 and I2) or (I1 and I3) or (I1 and I4) or (I1 and I5) or (I1 and I6) or (I1 and I7) \
        or (I2 and I3) or (I2 and I4) or (I2 and I5) or (I2 and I6) or (I2 and I7) \
        or (I3 and I4) or (I3 and I5) or (I3 and I6) or (I3 and I7) \
        or (I4 and I5) or (I4 and I6) or (I4 and I7) \
        or (I5 and I6) or (I5 and I7) \
        or (I6 and I7)
    return Q
     

def v2oo10(I1, I2, I3, I4, I5, I6, I7, I8, I9, I10):
    Q = False
    Q = (I1 and I2) or (I1 and I3) or (I1 and I4) or (I1 and I5) or (I1 and I6) or (I1 and I7) or (I1 and I8) or (I1 and I9) or (I1 and I10) \
            or (I2 and I3) or (I2 and I4) or (I2 and I5) or (I2 and I6) or (I2 and I7) or (I2 and I8) or (I2 and I9) or (I2 and I10) \
            or (I3 and I4) or (I3 and I5) or (I3 and I6) or (I3 and I7) or (I3 and I8) or (I3 and I9) or (I3 and I10) \
            or (I4 and I5) or (I4 and I6) or (I4 and I7) or (I4 and I8) or (I4 and I9) or (I4 and I10) \
            or (I5 and I6) or (I5 and I7) or (I5 and I8) or (I5 and I9) or (I5 and I10) \
            or (I6 and I7) or (I6 and I8) or (I6 and I9) or (I6 and I10) \
            or (I7 and I8) or (I7 and I9) or (I7 and I10) \
            or (I8 and I9) or (I8 and I10) \
            or (I9 and I10)
    return Q
    

def analog_to_bool(value, level_h, threshould):
    if level_h:
        if value >= threshould:
            return True
        else:
            return False       
    else: 
        if value <= threshould:
            return True
        else:
            return False
        
# Class Definition

class Plc(Process): 

    def  __init__(self, scan_cicle, opc_server, log_queue):
        super(Plc, self).__init__() 
        self.opc_conn = opc_server
        self.scan_cicle = scan_cicle        
        self.TON_1 = 10
        self.TON_2 = 10
        self.reset('TON_1')
        self.reset('TON_2')
        self.log_queue = log_queue
        print("-----PLC Created")

    def log(self, level, msg):
        self.log_queue.put((level, 'PLC', msg))

    def reset(self, ton):
        if ton=='TON_1':
            self.TON_1_TIMER = 0
            self.TON_1_IN = False
            self.TON_1_Q = False
        elif ton=='TON_2':
            self.TON_2_TIMER = 0
            self.TON_2_IN = False
            self.TON_2_Q = False
    
    def tick(self):
        # Update
        if self.TON_1_IN:
            self.TON_1_TIMER += self.scan_cicle 
        if self.TON_2_IN:
            self.TON_2_TIMER += self.scan_cicle
        # Is elapsed
        if self.TON_1_TIMER >= self.TON_1:
            self.TON_1_Q = True
        if self.TON_2_TIMER >= self.TON_2:
            self.TON_2_Q = True
        
        
    def run(self):
        print("-----PLC Started")
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

        # Init special variables
        OUTPUT_2 = False

        while True:
            start_time = current_milli_time()

           

            # Read
            inputs = opc.read_group('reader', self.opc_conn)

            INPUT_001_007    = [0] * 7
            INPUT_001_007[0] = inputs[0][1]
            INPUT_001_007[1] = inputs[1][1]
            INPUT_001_007[2] = inputs[2][1]
            INPUT_001_007[3] = inputs[3][1]
            INPUT_001_007[4] = inputs[4][1]
            INPUT_001_007[5] = inputs[5][1]
            INPUT_001_007[6] = inputs[6][1]
            
            INPUT_008       = inputs[7][1]

            INPUT_009_013    = [0] * 5
            INPUT_009_013[0] = inputs[8][1]
            INPUT_009_013[1] = inputs[9][1]
            INPUT_009_013[2] = inputs[10][1]
            INPUT_009_013[3] = inputs[11][1]
            INPUT_009_013[4] = inputs[12][1]

            INPUT_014_023    = [0] * 10
            INPUT_014_023[0] = inputs[13][1]
            INPUT_014_023[1] = inputs[14][1]
            INPUT_014_023[2] = inputs[15][1]
            INPUT_014_023[3] = inputs[16][1]
            INPUT_014_023[4] = inputs[17][1]
            INPUT_014_023[5] = inputs[18][1]
            INPUT_014_023[6] = inputs[19][1]
            INPUT_014_023[7] = inputs[20][1]
            INPUT_014_023[8] = inputs[21][1]
            INPUT_014_023[9] = inputs[22][1]

            INPUT_024_027    = [0] * 4
            INPUT_024_027[0] = inputs[23][1]
            INPUT_024_027[1] = inputs[24][1]
            INPUT_024_027[2] = inputs[25][1]
            INPUT_024_027[3] = inputs[26][1]

            INPUT_028_CMZ    = inputs[27][1]
            INPUT_029_CMZ         =  inputs[28][1]

            # Polarize
            INPUT_001_007_HH    = [True]*7
            INPUT_001_007_HH[0] = analog_to_bool(INPUT_001_007[0], True, 28800)
            INPUT_001_007_HH[1] = analog_to_bool(INPUT_001_007[1], True, 28800)
            INPUT_001_007_HH[2] = analog_to_bool(INPUT_001_007[2], True, 28800)
            INPUT_001_007_HH[3] = analog_to_bool(INPUT_001_007[3], True, 28800)
            INPUT_001_007_HH[4] = analog_to_bool(INPUT_001_007[4], True, 28800)
            INPUT_001_007_HH[5] = analog_to_bool(INPUT_001_007[5], True, 28800)
            INPUT_001_007_HH[6] = analog_to_bool(INPUT_001_007[6], True, 28800)

            INPUT_008_L        = analog_to_bool(INPUT_008, False, 6563)
        
            INPUT_009_013_HH    = [True]*5
            INPUT_009_013_HH[0] = analog_to_bool(INPUT_009_013[0], True, 15600)
            INPUT_009_013_HH[1] = analog_to_bool(INPUT_009_013[1], True, 15600)
            INPUT_009_013_HH[2] = analog_to_bool(INPUT_009_013[2], True, 20400)
            INPUT_009_013_HH[3] = analog_to_bool(INPUT_009_013[3], True, 20400)
            INPUT_009_013_HH[4] = analog_to_bool(INPUT_009_013[4], True, 20400)

            INPUT_014_023_HH    = [True]*10
            INPUT_014_023_HH[0] = analog_to_bool(INPUT_014_023[0], True, 20400)
            INPUT_014_023_HH[1] = analog_to_bool(INPUT_014_023[1], True, 20400)
            INPUT_014_023_HH[2] = analog_to_bool(INPUT_014_023[2], True, 20400)
            INPUT_014_023_HH[3] = analog_to_bool(INPUT_014_023[3], True, 20400)
            INPUT_014_023_HH[4] = analog_to_bool(INPUT_014_023[4], True, 20400)
            INPUT_014_023_HH[5] = analog_to_bool(INPUT_014_023[5], True, 20400)
            INPUT_014_023_HH[6] = analog_to_bool(INPUT_014_023[6], True, 20400)
            INPUT_014_023_HH[7] = analog_to_bool(INPUT_014_023[7], True, 20400)
            INPUT_014_023_HH[8] = analog_to_bool(INPUT_014_023[8], True, 20400)
            INPUT_014_023_HH[9] = analog_to_bool(INPUT_014_023[9], True, 20400)

            INPUT_024_027_HH    = [True]*4
            INPUT_024_027_HH[0] = analog_to_bool(INPUT_024_027[0], True, 15600)
            INPUT_024_027_HH[1] = analog_to_bool(INPUT_024_027[1], True, 15600)
            INPUT_024_027_HH[2] = analog_to_bool(INPUT_024_027[2], True, 15600)
            INPUT_024_027_HH[3] = analog_to_bool(INPUT_024_027[3], True, 15600)

            # Voting
            state_vote_2oo7_INPUT_001_007_ON  = v2oo7(INPUT_001_007_HH[0], INPUT_001_007_HH[1], INPUT_001_007_HH[2], INPUT_001_007_HH[3], INPUT_001_007_HH[4], INPUT_001_007_HH[5], INPUT_001_007_HH[6])
            state_vote_1oo7_INPUT_001_007_ON  = v1oo7(INPUT_001_007_HH[0], INPUT_001_007_HH[1], INPUT_001_007_HH[2], INPUT_001_007_HH[3], INPUT_001_007_HH[4], INPUT_001_007_HH[5], INPUT_001_007_HH[6])
            state_vote_2oo5_INPUT_009_013     = v2oo5(INPUT_009_013_HH[0], INPUT_009_013_HH[1], INPUT_009_013_HH[2], INPUT_009_013_HH[3], INPUT_009_013_HH[4])
            state_vote_2oo10_INPUT_014_023   = v2oo10(INPUT_014_023_HH[0], INPUT_014_023_HH[1], INPUT_014_023_HH[2], INPUT_014_023_HH[3], INPUT_014_023_HH[4], INPUT_014_023_HH[5], INPUT_014_023_HH[6], INPUT_014_023_HH[7], INPUT_014_023_HH[8], INPUT_014_023_HH[9])               
            state_vote_2oo4_INPUT_024_027     = v2oo4(INPUT_024_027_HH[0], INPUT_024_027_HH[1], INPUT_024_027_HH[2], INPUT_024_027_HH[3])

            # TONs
            # TON_1
            if  state_vote_2oo7_INPUT_001_007_ON:
                self.TON_1_IN = True
            else:
                self.reset('TON_1')
            state_vote_2oo7_INPUT_001_007 = self.TON_1_Q and state_vote_2oo7_INPUT_001_007_ON
            
            # TON_2
            if state_vote_1oo7_INPUT_001_007_ON:
                self.TON_2_IN = True
            else:
                self.reset('TON_2')
            state_vote_1oo7_INPUT_001_007 = self.TON_2_Q and state_vote_1oo7_INPUT_001_007_ON
            
            # Rung 1
            OUTPUT_1 = state_vote_2oo7_INPUT_001_007 or (state_vote_1oo7_INPUT_001_007 and INPUT_008_L) or \
                state_vote_2oo5_INPUT_009_013 or state_vote_2oo10_INPUT_014_023 or state_vote_2oo4_INPUT_024_027        
           

            # Rung 3
            if INPUT_028_CMZ==1:
                # Force Reset
                OUTPUT_2 = False
            else:
                OUTPUT_2 = (OUTPUT_2 or (state_vote_2oo7_INPUT_001_007 or state_vote_1oo7_INPUT_001_007 or INPUT_008_L))
            
            # Rung 4
            OUTPUT_3 = state_vote_2oo5_INPUT_009_013 or state_vote_2oo10_INPUT_014_023 or state_vote_2oo4_INPUT_024_027

            # Rung 5
            OUTPUT_4 = state_vote_2oo7_INPUT_001_007 or (state_vote_1oo7_INPUT_001_007 and INPUT_008_L) or \
                state_vote_2oo5_INPUT_009_013 or state_vote_2oo10_INPUT_014_023 or state_vote_2oo4_INPUT_024_027

            # Write 
            output = [
                ('CPU_PLC.OUTPUT_1',OUTPUT_1), \
                ('CPU_PLC.OUTPUT_2', OUTPUT_2), \
                ('CPU_PLC.OUTPUT_3', OUTPUT_3), \
                ('CPU_PLC.OUTPUT_4', OUTPUT_4)\
            ]
            self.opc_conn.update(opc.write_batch(output, self.opc_conn))
            self.tick()
            end_time = current_milli_time()
            delta = (end_time - start_time)/1000.0
            if delta > self.scan_cicle:
                self.log(4, "----PLC:: DEADLINE PASSED {}".format(delta))
            else:
                start_sleep_time = current_milli_time()
                sleep(self.scan_cicle - delta)
                end_sleep_time = current_milli_time()
                delta_over = (end_sleep_time - start_sleep_time) / 1000.0
                self.log(0, "----PLC::OK {} / {}".format(delta, self.scan_cicle - delta))
                self.log(0, "----PLC Over {}".format(delta_over))