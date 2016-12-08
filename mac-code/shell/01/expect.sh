#! /usr/bin/expect -f

set timeout 15

set num [lindex $argv 0]

spawn sudo su
expect {
	"yes/no" {send "yes\n"; exp_continue}
	"Password:" {send "woaiwojia.523\n"}
}

expect "sh-3.2#"

send "mkdir root$num\n"
#expect eof

interact

#expect "sh-3.2#"

#send "echo root\n"

#expect "root"

#send "exit\n"

#expect eof
