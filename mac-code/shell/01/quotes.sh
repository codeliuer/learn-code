#! /bin/bash

num='num'
new='new'

trap 'echo ${num}; echo ${new}' SIGINT SIGQUIT

num=1
new=2

sleep 20
