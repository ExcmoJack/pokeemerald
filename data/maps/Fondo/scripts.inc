Fondo_MapScripts::
	@ map_script MAP_SCRIPT_ON_TRANSITION, Fondo_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Fondo_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Fondo_OnWarp
	.byte 0

Fondo_OnFrame:
	map_script_2 VAR_CONCURSO_0, 0, Fondo_Intro
	map_script_2 VAR_CONCURSO_0, 2, Fondo_Intro2
	map_script_2 VAR_CONCURSO_0, 5, Fondo_Fin
	.2byte 0

Fondo_OnWarp:
	map_script_2 VAR_CONCURSO_0, 0, Fondo_HidePlayer
	map_script_2 VAR_CONCURSO_0, 2, Fondo_HidePlayer
	map_script_2 VAR_CONCURSO_0, 5, Fondo_HidePlayer
	.2byte 0

Fondo_HidePlayer:
	applymovement OBJ_EVENT_ID_PLAYER, Fondo_HidePlayer_Movement
	@ waitmovement OBJ_EVENT_ID_PLAYER
	end

Fondo_Intro:
	lock
	callnative setMsgboxAlpha
	callnative setMsgboxCenter
	msgbox Fondo_Titulo_Text, MSGBOX_SIGN
	closemessage
	msgbox Fondo_Dia1_Text, MSGBOX_SIGN
	closemessage
	setflag FLAG_LUCES
	setflag FLAG_JAIZU
	setvar VAR_CONCURSO_0, 1
	warpsilent MAP_EXTERIOR, 0xFF, 9, 9
	release
	end

Fondo_Intro2:
	lock
	callnative setMsgboxAlpha
	callnative setMsgboxCenter
	msgbox Fondo_Dia25_Text, MSGBOX_DEFAULT
	warpsilent MAP_PISO_FRANCO, 0xFF, 9, 9
	delay 120
	release
	end

Fondo_Fin:
	lock
	callnative setMsgboxAlpha
	callnative setMsgboxCenter
	msgbox Fondo_Continuara_Text, MSGBOX_DEFAULT
	@ warp MAP_PISO_FRANCO, 0xFF, 9, 9
	delay 30
	release
	end

Fondo_HidePlayer_Movement:
	set_invisible
	step_end

Fondo_Titulo_Text:
	.string "{SHIFT_TEXT 56}12 días de Navidad$"
Fondo_Dia1_Text:
	.string "{SHIFT_TEXT 86}Día 1$"

Fondo_Dia25_Text:
	.string "{SHIFT_TEXT 86}Día 24$"

Fondo_Continuara_Text:
	.string "{SHIFT_TEXT 70}Continuará…$"
