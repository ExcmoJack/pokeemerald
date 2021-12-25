.set LOCALID_GORDO, 1

Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Exterior_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Exterior_OnWarp
	.byte 0

Exterior_OnWarp:
	map_script_2 VAR_CONCURSO_0, 1, Exterior_HidePlayer
	.2byte 0

Exterior_OnFrame:
	map_script_2 VAR_CONCURSO_0, 1, Exterior_Intro
	.2byte 0

Exterior_HidePlayer:
	applymovement OBJ_EVENT_ID_PLAYER, Exterior_HidePlayer_Movement
	end

Exterior_Intro:
	lock
	callnative setMsgboxCenter
	delay 60
	fadescreen FADE_TO_BLACK
	msgbox Exterior_Dia2_Text, MSGBOX_SIGN
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_GORDO, Exterior_Gordo_1_Movement
	waitmovement LOCALID_GORDO
	delay 60
	fadescreen FADE_TO_BLACK
	msgbox Exterior_Dia3_Text, MSGBOX_SIGN
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_GORDO, Exterior_Gordo_2_Movement
	waitmovement LOCALID_GORDO
	delay 60
	fadescreen FADE_TO_BLACK
	msgbox Exterior_Dia12_Text, MSGBOX_SIGN
	fadescreen FADE_FROM_BLACK
	callnative resetMsgboxAlpha
	callnative setMsgboxDown
	showmonpic SPECIES_XATU, 21, 6
	msgbox Exterior_Intro_Text1, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	applymovement LOCALID_GORDO, Exterior_Gordo_3_Movement
	waitmovement LOCALID_GORDO
	showmonpic SPECIES_WOBBUFFET, 21, 6
	msgbox Exterior_Intro_Text2, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	setvar VAR_CONCURSO_0, 2
	delay 40
	warp MAP_FONDO, 0xFF, 9, 9
	release
	end

Exterior_HidePlayer_Movement:
	set_invisible
	step_end

Exterior_Gordo_1_Movement:
	delay_16
	face_right
	delay_8
	face_left
	delay_16
	face_up
	step_end

Exterior_Gordo_2_Movement:
	delay_16
	lock_facing_direction
	walk_right
	delay_8
	walk_left
	delay_16
	walk_down
	delay_16
	walk_up
	unlock_facing_direction
	step_end

Exterior_Gordo_3_Movement:
	walk_in_place_fastest_down
	emote_question_mark
	delay_16
	walk_right
	walk_right
	walk_right
	delay_8
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_16
	walk_left
	walk_left
	set_invisible
	step_end

Exterior_Dia2_Text:
	.string "{SHIFT_TEXT 86}Día 2$"

Exterior_Dia3_Text:
	.string "{SHIFT_TEXT 86}Día 3$"

Exterior_Dia12_Text:
	.string "{SHIFT_TEXT 86}Día 12$"

Exterior_Intro_Text1:
	.string "Bueno chicos, ya va siendo hora\nde ir preparando la cena.\p{COLOR BLUE}Reoneky{COLOR DARK_GRAY}, ¿has aparcado bien esta vez?$"
	
Exterior_Intro_Text2:
	.string "¡La vin compae! Eso pasó hace mucho ya,\n{COLOR LIGHT_BLUE}Eingsito{COLOR DARK_GRAY}, deja de recordármelo.$"
