#! /bin/bash
##########################################################################
# local and git sync
##########################################################################

workdir=`pwd`
curtm=`date "+%Y-%m-%d %H:%M:%S"`


function git_add()
{
	local addfile=${1}

	git add "${addfile}"
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
ls -al ${workdir} | egrep '^-' | awk '{print $9}' | egrep '.*(\.(c|C|c(pp|\+\+)|sh|php|h|python))$' | while read file
do
	git_add ${file}
done

git_commit
git_push
