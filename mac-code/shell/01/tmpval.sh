#! /bin/bash

# local: can only be used in a function
#local val='HOME'

function func()
{
	val='HOME'
	export val
}

export var='HOME1'

func
