#! /bin/bash
############################################################################
##### debug
#PS4='+${FUNCNAME[0]}(${LINENO})'

#set -x

############################################################################
##### network check

function write_mail()
{
	if [ ${1} -eq 0 ]; then
		echo 'network disconnect' >>${MAIL}
		exit 1
	fi
}

function network()
{
	local num=30	# 30 seconds

	until [ ${num} -eq 0 ]
	do
		curl baidu.com >/dev/null 2>&1

		if [ $? -eq 0 ]; then
			break;
		fi

		num=$[ ${num}-1 ]
		write_mail ${num}

		sleep 1
	done
}

############################################################################
##### git

function update()
{
	git pull
}

function addfile()
{
	git add *.[ch]
	git add *.cpp
	git add *.sh
}

function commit()
{
	name=${HOSTNAME}
	curt=`date`

	git commit -m "${name} ${curt}"
}

function git_opt()
{
	update
	
	addfile

	commit
}


############################################################################
network

git_opt









