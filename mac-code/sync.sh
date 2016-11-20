#! /bin/bash
##########################################################################
# local and git sync
##########################################################################

workdir=`pwd`
curtm=`date "+%Y-%m-%d %H:%M:%S"`


function add_file()
{
	local tmpdir=`pwd`

	ls -al ${tmpdir} | egrep '^-' | awk '{print $9}' | egrep '.*(\.(c|C|c(pp|\+\+)|sh|php|h|python))$' | while read file
	do
		git add ${file}
	done
}

function add_dir()
{
	local tmpfile=`pwd`

	ls -al ${tmpfile} | egrep '^d' | awk '$9!="." && $9!=".." {print $9}' | while read file
	do
		cd ${file}

		git_add
	done
}

function git_add()
{
	add_file
	add_dir
}

function git_commit()
{
	git commit -m "${workdir} ${curtm}"
}

function git_pull()
{
	git pull
}

function git_push()
{
	git push
}

git_pull
git_add
git_commit
git_push
