#!/usr/bin/env python

import os
import shutil

files = [f for f in os.listdir('.') if os.path.isfile(f)]


for f in  files:
    if '.' in f:
        filename = f.split('.')
	if filename[0].endswith(',0'):
	    print filename
            destFilename = filename[0][:-2] + '.' + filename[1]
            shutil.copy2('./'+ '.'.join(filename), './' + destFilename) 
        
