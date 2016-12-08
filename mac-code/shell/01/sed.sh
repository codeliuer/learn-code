#! /bin/bash

echo "${PATH}" | sed 's/^:/.:/
					  s/::/:.:/g
					  s/:$/:./
					  s/:/ /g'

echo "name 
		is \
		liuwei"
