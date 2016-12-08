 #! /bin/bash
##########################################################################
# local and git sync
##########################################################################

workdir=`pwd`
curtm=`date "+%Y-%m-%d %H:%M:%S"`


function add_file()
{
	local file=
	local tmpdir=`pwd`

	ls -al ${tmpdir} | egrep '^-' | awk '{print $9}' | egrep '.*(\.(c|C|c(pp|\+\+)|sh|php|h|python))$' | while read file
	do
		git add ${file}
	done
}

function add_dir()
{
	local file=
	local tmpdir=`pwd`

	if [[ -z "${user}" ]]
	then
		user=`id -un`
	fi

	ls -al ${tmpdir} | egrep '^d' | awk '$3==user && $9!="." && $9!=".." {print $9}' user="${user}" | while read dir
	do
		cd "${tmpdir}/${dir}"

		git_add

		cd ".."
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

#git_pull
#git_add
#git_commit
#git_push
