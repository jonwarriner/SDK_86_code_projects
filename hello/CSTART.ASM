;/*
; *                 INTEL CORPORATION PROPRIETARY INFORMATION
; *
; *           This software is supplied under the terms of a
; *           license agreement or non-disclosure agreement with
; *           Intel Corporation and may not be copied or disclosed
; *           except in accordance with the terms of that agreement.
; *
; *   Title:  cstart
; */
; This is the starting point for all c programs.
; $Version: 1.38 $
; Copyright (C) 1988 Intel Corporation, ALL RIGHTS RESERVED

%define(controls)(module=cstart fixedparams %controls)

%'      environment symbols

%*define(embedded)      (%set(HOSTED, 0)%set(MS_DOS,0)%set(RMX, 0))
%*define(dos)           (%set(HOSTED, 1)%set(MS_DOS,1)%set(RMX, 0))
%*define(rmx1)          (%set(HOSTED, 1)%set(MS_DOS,0)%set(RMX, 1))
%*define(rmx2)          (%set(HOSTED, 1)%set(MS_DOS,0)%set(RMX, 1))

%*define(em)	(%embedded)


%'      define the default environment
%dos

$include(:include:util.ah)

%set(medium_rom, %far_code and %const_in_code)

	%DATA	segment
		dw	?
	%DATA	ends

	%CONST	segment
		dw	?
	%CONST	ends

%if(not %i286_asm)
then(
	%STACK	segment
	stacktop	dw	?
	%STACK	ends
)fi

;
;	External data and program linkage:
;
%if(%HOSTED)
then(
  %' define external linkage for parameters to main()
  %'
  %if(%medium_rom)
  then(
	extrn	_argc:word
	extrn	_argv:%ptr
  )else(
	%extern(word, _argc)
	%extern(%ptr, _argv)
  )fi
)fi

%if(not %RMX)
then(
	%' the coprocessor is already initialized under RMX
	%'
	%' extrn	init87:far  jpw not needed
)fi
	%'extern_fnc(_thread_init) jpw not needed
	%extern_fnc(main)

%if(%HOSTED)
then(
	%' these CLIB functions require operating system support
	%'
	%extern_fnc(_exit_init)
	%extern_fnc(_stdio_init)
	%extern_fnc(exit)
	%extern_fnc(_get_args)
  %if(%RMX)
  then(
	%extern_fnc(_global_init)
  )fi
)fi

%code	segment

begin:
	;
	; Initialize the C-Library and the environment (if necessary):
	;
%if(not %RMX)
then(
	%' call	init87			; initialize the coprocessor  jpw not needed
)fi

%if(not %HOSTED)
then(
	%'call	_thread_init		; initialize CLIB thread data jpw not needed
)else(
  %if(%RMX)
  then(
	call	_global_init		; initialize RMX specific global data
	call	_thread_init		; initialize CLIB thread data
  )fi
	call	_exit_init		; initialize CLIB exit handlers
	call	_stdio_init		; initialize CLIB standard streams
  %if(%MS_DOS)
  then(
	call	_thread_init		; initialize CLIB thread data
  )fi
	call	_get_args		; setup parameters to main()

  %if(%far_data)
  then(
    %' define code for passing paramerers to main() for compact and large models
    %'
    %*define(push_argc)
    (
      %if(%set_ds or %medium_rom)
      then(
	mov	cx, seg _argc
      )else(
	mov	cx, ds
      )fi
	mov	es, cx
	push	es:_argc		; push number of arguments to main()
    )
    %*define(push_argv)
    (
      %if(%set_ds or %medium_rom)
      then(
	mov	cx, seg _argv
      )else(
	mov	cx, ds
      )fi
	mov	es, cx
	push	word ptr es:_argv+2	; push address of array containing argument addresses
	push	word ptr es:_argv
    )
  )else(
    %' define code for passing paramerers to main() for small and medium model
    %'
    %*define(push_argc)
    (
	push	_argc			; push number of arguments to main()
    )
    %*define(push_argv)
    (
	push	_argv			; push address of array containing argument addresses
    )
  )fi
)fi

	;
	; Invoke the user's program:
	;
%if(not %HOSTED)
then(
	call	main			; no parameters passed to main()
	hlt				; ERROR:  no return expected in a 
					;         non-hosted environment

)else(
  %' set up command line arguments for main()
  %'
  %if(%fpl)
  then(
	%push_argc
	%push_argv
  )else(
	%push_argv
	%push_argc
  )fi
	call	main			; call the user's programs
	push	ax			; set the termination value
	call	exit			; and quietly exit
)fi

%code	ends

	end	begin,	ds:%dgroup, %'
			ss:%sgroup %if(not %i286_asm)then( :stacktop )fi
