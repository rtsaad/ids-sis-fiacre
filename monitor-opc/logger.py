import time 
import logging
import logging.handlers
from multiprocessing import Process, Queue

current_milli_time = lambda: int(round(time.time() * 1000))

class Logger(Process): 

    FORMAT = '%(asctime) %(level) %(process)::'

    def  __init__(self, log_q, level):
        super(Logger, self).__init__() 
        self.log_q = log_q 
        self.level = level
        print("-----Logger Created")

    def show(self, m, extra=None):
        if extra:
            print('{} {}: {}'.format(extra['level'], extra['process'], m))
        else:
            print('{}'.format(m))

    def run(self):
        print("-----Logger Started")
        # Level: 0-debug, 1-info, 2-warning, 3-error, 4-critical
        # Message: level, process, message
        # TODO: loggin not working, using print instead.
        logging.basicConfig(format=self.FORMAT)
        while True:
            (l, p, m) = self.log_q.get(block=True)
            # Check level of logs
            if(l < self.level):
                continue

            log = logging.getLogger(__name__)           
            if l==0:
                #log.debug(m,    extra={'process': p, 'level': 'DEBUG'})
                self.show(m,    extra={'process': p, 'level': 'DEBUG'})
            elif l==1:
                #log.info(m,     extra={'process': p, 'level': 'INFO'})
                self.show(m,    extra={'process': p, 'level': 'INFO'})
            elif l==2:
                #log.warning(m,  extra={'process': p, 'level': 'WARNING'})
                self.show(m,    extra={'process': p, 'level': 'WARNING'})
            elif l==3:
                #log.error(m,    extra={'process': p, 'level': 'ERROR'})
                self.show(m,    extra={'process': p, 'level': 'ERROR'})
            elif l==4:
                #log.critical(m, extra={'process': p, 'level': 'CRITICAL'})
                self.show(m,    extra={'process': p, 'level': 'CRITICAL'})