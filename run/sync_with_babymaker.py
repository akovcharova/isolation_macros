#! /usr/bin/env python

from tempfile import mkdtemp
import subprocess
from os import chdir,getcwd,listdir,path
from shutil import rmtree,copy2

orig_dir = getcwd()
temp_dir = mkdtemp()

chdir(temp_dir)
 
subprocess.call(['git','clone','git@github.com:manuelfs/babymaker'])

babymaker = temp_dir+'/babymaker'

cfg_path = babymaker+'/variables'
cfg_files = [ file for file in listdir(cfg_path) if path.isfile(cfg_path+'/'+file) ]

for file in cfg_files:
    src = babymaker+'/variables/'+file
    dst = orig_dir+'/txt/small_tree_cfg'
    copy2(src,dst)

chdir(orig_dir)
rmtree (temp_dir)
