import random
import csv


class OpcCsv:
    OPC_VARIABLES = {}
    OPC_VARIABLES_LIST = []
    OPC_VARIABLES_LEVELS = ['LLL', 'LL', 'L', 'H', 'HH', 'HHH']
    OPC_VARIABLES_TYPES = ['DIGITAL', 'ANALOG']
    OPC_VARIABLES_DIRECTION = ['INPUT', 'OUTPUT', 'RESET']
    filename = ''

    def  __init__(self):
        self.filename = 'opc_variables'
        self.read_csv()

    def set_level(self, level, threshould):
        if level in self.OPC_VARIABLES_LEVELS:
            return (level, threshould)
        else:
            return None

    def add_var(self, suffix, name, type, direction, min=0, max=1, levels=[], off=0):

        item = None
        if direction not in self.OPC_VARIABLES_DIRECTION:
            raise Exception('OPC::INVALID_DIRECTION')

        item = None

        if type == 'DIGITAL':
            item = (suffix, name, 'DIGITAL', direction, 0, 1, [('L', True), ('H', False)], off)
        else:
            # Check Levels
            def get_key(item):
                if item[0] == 'LLL':
                    return 1
                elif item[0] == 'LL':
                    return 2
                elif item[0] == 'L':
                    return 3
                elif item[0] == 'H':
                    return 4
                elif item[0] == 'HH':
                    return 5
                elif item[0] == 'HHH':
                    return 6

            levels.sort(key=get_key)
            temp_val = 0
            for level in levels:
                if temp_val > level[1]:
                    raise Exception('OPC::INVALID_LEVEL')
                temp_val = level[1]

            if max < min:
                raise Exception('OPC::INVALID_MAX_MIN')
            item = (suffix, name, type, direction, min, max, levels, off)

        self.OPC_VARIABLES[suffix + '.' + name] = item
        self.OPC_VARIABLES_LIST.append(item)

    def read_csv(self):
        # CSV Template
        # sufix, name, type, [min, max, L, threshould_L, H, threshould_H]
        with open(self.filename + '.csv') as csvfile:
            csvreader = csv.reader(csvfile, delimiter=',', quotechar='"')
            for row in csvreader:
                if len(row) == 0 or row[0] == '#':
                    continue
                suffix = row[0].strip()
                name = row[1].strip()
                ttype = row[2].strip()
                direction = row[3].strip()
                if ttype == 'DIGITAL' or ttype == 'RESET':
                    self.add_var(suffix, name, ttype, direction)
                else:
                    min = int(row[4])
                    max = int(row[5])
                    off = int(row[len(row) - 1])
                    i = 6
                    levels = []
                    while i < len(row) - 2:
                        levels.append(self.set_level(row[i].strip(), int(row[i + 1])))
                        i += 2
                    self.add_var(suffix, name, ttype, direction, min, max, levels, off)

    def list_variables(self, direction=None):
        variables = []
        for var in self.OPC_VARIABLES_LIST:
            if direction:
                if direction == var[3]:
                    variables.append(var[0] + '.' + var[1])
            else:
                variables.append(var[0] + '.' + var[1])
        return variables

    def get_type(self, var):
        return var[2]

    ## Available levels
    def get_levels(self, var):
        levels = []
        for level in var[6]:
            levels.append(level[0])
        return levels

    def release_value(self, var):
        return var[7]

    ## Force values
    def force_value(self, level, var):
        ttype = var[2]
        if ttype == 'DIGITAL' or ttype == 'RESET':
            if level == 'L':
                return False
            else:
                return True
        min = var[4]
        max = var[5]
        levels = var[6]
        value = None
        for l in levels:
            if l[0] == level:
                value = l[1]
                if level in ['LLL', 'LL', 'L']:
                    value = value - 20 #min + ((value - min) / 2)
                else:
                    value = value + 20 #max - ((max - value) / 2)
        return value

    # Analog to Boolean
    def analog_to_boolean(self, var, value, level):
        var_definition = self.OPC_VARIABLES[var]
        ttype = var_definition[2]
        if ttype == 'DIGITAL':
            return value
        else:
            # Check min max
            if value > max or value < min:
                raise Exception('OPC::INVALID_MAX_MIN')
            levels = var_definition[6]
            for l in levels:
                if l[0] == level:
                    if level in ['LLL', 'LL', 'L']:
                        if value < l[1]:
                            return True
                        else:
                            return False
                    else:
                        if value > l[1]:
                            return True
                        else:
                            return False