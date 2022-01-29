.set LOCALID_SERGIO, 2
.set LOCALID_XIROS,  3
.set LOCALID_YURI,   4
.set LOCALID_JACK,   5
.set LOCALID_ZEIN,   6
.set LOCALID_REO,    7
.set LOCALID_EING,   8
.set LOCALID_JAIZU,  9

.set MUG_X, 21
.set MUG_Y, 6

PisoFranco_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PisoFranco_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PisoFranco_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PisoFranco_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PisoFranco_OnWarp
	.byte 0

PisoFranco_OnLoad:
	compare VAR_CONCURSO_0, 3
	goto_if_ge PisoFranco_OnLoad_1
	end

PisoFranco_OnLoad_1:
	setmetatile 2, 5, 0x288, 1
	setmetatile 3, 5, 0x289, 1
	setmetatile 4, 5, 0x28A, 1
	setmetatile 2, 6, 0x290, 1
	setmetatile 3, 6, 0x291, 1
	setmetatile 4, 6, 0x292, 1
	setmetatile 3, 7, 0x299, 1
	end

PisoFranco_OnWarp:
	map_script_2 VAR_CONCURSO_0, 2, PisoFranco_HidePlayer
	map_script_2 VAR_CONCURSO_0, 4, PisoFranco_HidePlayer2
	.2byte 0

PisoFranco_OnFrame:
	map_script_2 VAR_CONCURSO_0, 2, PisoFranco_Evento_1
	map_script_2 VAR_CONCURSO_0, 4, PisoFranco_Evento_2
	.2byte 0

PisoFranco_HidePlayer2:
	setobjectxy LOCALID_SERGIO, 9, 7
	setobjectxy LOCALID_YURI, 3, 7
	applymovement OBJ_EVENT_ID_PLAYER, PisoFranco_HidePlayer_Movement
	end

PisoFranco_OnTransition:
	compare VAR_CONCURSO_0, 4
	goto_if_eq PisoFranco_OnTransition1
	end

PisoFranco_OnTransition1:
	setobjectmovementtype LOCALID_SERGIO, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_EING, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_REO, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_XIROS, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype LOCALID_YURI, MOVEMENT_TYPE_FACE_UP
	end

PisoFranco_HidePlayer:
	applymovement OBJ_EVENT_ID_PLAYER, PisoFranco_HidePlayer_Movement
	end

PisoFranco_Evento_1:
	lock
	callnative resetMsgboxAlpha
	callnative setMsgboxDown
	showmonpic SPECIES_GIRAFARIG, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Sergio_1, MSGBOX_DEFAULT
	applymovement LOCALID_SERGIO, PisoFranco_Evento_Movement_Sergio_1
	waitmovement LOCALID_SERGIO
	msgbox PisoFranco_Evento_Text_Sergio_2, MSGBOX_DEFAULT
	closemessage	
	hidemonpic
	showmonpic SPECIES_ZEKROM, MUG_X, MUG_Y
	applymovement LOCALID_ZEIN, Common_Movement_QuestionMark
	waitmovement LOCALID_ZEIN
	msgbox PisoFranco_Evento_Text_Zein_1, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	special SpawnCameraObject
	fadenewbgm MUS_FOLLOW_ME
	applymovement OBJ_EVENT_ID_CAMERA, PisoFranco_Evento_Movement_Cam_1
	waitmovement OBJ_EVENT_ID_CAMERA
	addobject LOCALID_JAIZU
	playse SE_EXIT
	waitse
	applymovement OBJ_EVENT_ID_CAMERA, PisoFranco_Evento_Movement_Cam_2
	applymovement LOCALID_JAIZU, PisoFranco_Evento_Movement_Jaizu_1
	waitmovement LOCALID_JAIZU
	special RemoveCameraObject
	showmonpic SPECIES_PANCHAM, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Jaizu_1, MSGBOX_DEFAULT
	hidemonpic
	closemessage
	applymovement LOCALID_EING, Common_Movement_WalkInPlaceFastestLeft
	waitmovement LOCALID_EING
	showmonpic SPECIES_XATU, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Eing_1, MSGBOX_DEFAULT
	hidemonpic
	closemessage
	applymovement LOCALID_ZEIN, PisoFranco_Evento_Movement_Zein_1
	waitmovement LOCALID_ZEIN
	showmonpic SPECIES_ZEKROM, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Zein_2, MSGBOX_DEFAULT
	hidemonpic
	closemessage
	applymovement LOCALID_ZEIN, PisoFranco_Evento_Movement_Zein_2
	waitmovement LOCALID_ZEIN
	playse SE_EXIT
	removeobject LOCALID_ZEIN
	applymovement LOCALID_JAIZU, Common_Movement_WalkInPlaceFastestDown
	waitmovement LOCALID_JAIZU
	showmonpic SPECIES_PANCHAM, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Jaizu_2, MSGBOX_DEFAULT
	hidemonpic
	closemessage
	applymovement LOCALID_JAIZU, PisoFranco_Evento_Text_Jaizu_3
	waitmovement LOCALID_JAIZU
	playse SE_EXIT
	removeobject LOCALID_JAIZU
	fadedefaultbgm
	applymovement LOCALID_EING, Common_Movement_WalkInPlaceFastestUp
	waitmovement LOCALID_EING
	showmonpic SPECIES_GIRAFARIG, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Sergio_3, MSGBOX_DEFAULT
	applymovement LOCALID_SERGIO, PisoFranco_Evento_Movement_Sergio_2
	waitmovement LOCALID_SERGIO
	msgbox PisoFranco_Evento_Text_Sergio_4, MSGBOX_DEFAULT
	applymovement LOCALID_SERGIO, PisoFranco_Evento_Movement_Sergio_3
	waitmovement LOCALID_SERGIO
	msgbox PisoFranco_Evento_Text_Sergio_5, MSGBOX_DEFAULT
	applymovement LOCALID_SERGIO, Common_Movement_WalkInPlaceFastestDown
	waitmovement LOCALID_SERGIO
	closemessage
	hidemonpic
	showmonpic SPECIES_WOBBUFFET, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Reonequi_1, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_GIRAFARIG, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Sergio_6, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_LUCARIO, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Yuri_1, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_WYNAUT, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Jack_1, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_GIRAFARIG, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Sergio_7, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_NATU, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Xiros_1, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_XATU, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Eing_2, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_NATU, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Xiros_2, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_WOBBUFFET, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Reonequi_2, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_GIRAFARIG, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Sergio_8, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_LUCARIO, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Yuri_2, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	applymovement LOCALID_YURI, PisoFranco_Evento_Movement_Yuri_1
	waitmovement LOCALID_XIROS
	showmonpic SPECIES_XATU, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Eing_3, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_LUCARIO, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Yuri_4, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	setmetatile 2, 5, 0x288, 1
	setmetatile 3, 5, 0x289, 1
	setmetatile 4, 5, 0x28A, 1
	setmetatile 2, 6, 0x290, 1
	setmetatile 3, 6, 0x291, 1
	setmetatile 4, 6, 0x292, 1
	setmetatile 3, 7, 0x299, 1
	special DrawWholeMapView
	playse SE_SWITCH
	waitse
	delay 12
	showmonpic SPECIES_LUCARIO, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Yuri_3, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	setvar VAR_CONCURSO_0, 3
	warpsilent MAP_SECRET_BASE_TREE2, 0xFF, 9, 13
	release
	end

PisoFranco_Evento_2:
	lock
	showmonpic SPECIES_LUCARIO, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Yuri_5, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	showmonpic SPECIES_GIRAFARIG, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Sergio_9, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	special StopMapMusic
	playse SE_BALL_TRAY_EXIT
	waitse
	applymovement LOCALID_SERGIO, Common_Movement_ExclamationMark
	waitmovement LOCALID_SERGIO
	applymovement LOCALID_SERGIO, Common_Movement_WalkInPlaceFastestUp
	waitmovement LOCALID_SERGIO
	showmonpic SPECIES_GIRAFARIG, MUG_X, MUG_Y
	msgbox PisoFranco_Evento_Text_Sergio_10, MSGBOX_DEFAULT
	applymovement LOCALID_SERGIO, Common_Movement_WalkInPlaceFastestDown
	waitmovement LOCALID_SERGIO
	msgbox PisoFranco_Evento_Text_Sergio_11, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	delay 30
	setvar VAR_CONCURSO_0, 5
	warpsilent MAP_FONDO, 0xFF, 9, 9
	release
	end

PisoFranco_HidePlayer_Movement:
	set_invisible
	step_end

PisoFranco_Evento_Movement_Sergio_1:
	walk_down
	step_end

PisoFranco_Evento_Movement_Sergio_2:
	walk_left
	step_end

PisoFranco_Evento_Movement_Sergio_3:
	walk_right
	step_end

PisoFranco_Evento_Movement_Cam_1:
	walk_down
	walk_down
	walk_down
	step_end

PisoFranco_Evento_Movement_Cam_2:
	walk_up
	walk_up
	walk_up
	step_end

PisoFranco_Evento_Movement_Jaizu_1:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PisoFranco_Evento_Movement_Zein_1:
	jump_in_place_right
	step_end

PisoFranco_Evento_Movement_Zein_2:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	set_invisible
	step_end

PisoFranco_Evento_Text_Jaizu_3:
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_in_place_fastest_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	set_invisible
	step_end

PisoFranco_Evento_Movement_Yuri_1:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

PisoFranco_Evento_Text_Sergio_1:
@                                                   |
	.string "Bueno. Como ya sabéis, hoy nos\n"
	.string "reunimos todos para conmemorar la\l"
	.string "operación {COLOR RED}RoomHarola{COLOR DARK_GRAY}.$"

PisoFranco_Evento_Text_Sergio_2:
	.string "Es un placer teneros a todos de nuevo\n"
	.string "por aquí algo más de un año después.\p"
	.string "Veo que seguís hackeando habitaciones\n"
	.string "por vuestra cuenta…$"

PisoFranco_Evento_Text_Zein_1:
	.string "Bueno, yo he venido aquí por las lolis.\n"
	.string "¿Dónde están las lolis?$"

PisoFranco_Evento_Text_Jaizu_1:
	.string "¿Alguien ha dicho lolis?\n"
	.string "¿Dónde están las lolis?$"

PisoFranco_Evento_Text_Eing_1:
	.string "¡Dijimos por los {COLOR RED}loles{COLOR DARK_GRAY},\n"
	.string "no por las {COLOR RED}lolis{COLOR DARK_GRAY}!$"

PisoFranco_Evento_Text_Zein_2:
	.string "¡Pues yo me voy a buscar lolis!$"

PisoFranco_Evento_Text_Jaizu_2:
	.string "¡Espera!\n"
	.string "{PAUSE_UNTIL_PRESS}¡Me voy contigo!$"

PisoFranco_Evento_Text_Sergio_3:
@                                                   |
	.string "No pasa nada, caballeros, sabía\n"
	.string "que harían esto desde el principio.$"

PisoFranco_Evento_Text_Sergio_4:
	.string "Tampoco hubiéramos llegado muy lejos\n"
	.string "con ellos con esa actitud.$"

PisoFranco_Evento_Text_Sergio_5:
	.string "En fin, nosotros a lo nuestro.\n"
	.string "Como ya sabéis, toda la mafia de\l"
	.string "{COLOR RED}DonRamón{COLOR DARK_GRAY} nos está buscando.\p"
	.string "No contábamos con que nos pillase\n"
	.string "con las manos en la masa.\p"
	.string "Con todo el dolor del alma,\n"
	.string "Tuvimos que sacrificar a {COLOR LIGHT_GREEN}Pablito{COLOR DARK_GRAY}.\p"
	.string "Espero que no haya sufrido mucho,\n"
	.string "el pobrecillo.$"

PisoFranco_Evento_Text_Reonequi_1:
	.string "Creo que el {COLOR RED}Mewtwo{COLOR DARK_GRAY} con el que me\n"
	.string "enfrenté se lo llevó.\p"
	.string "No sé cuáles eran sus intenciones\n"
	.string "exactamente…$"

PisoFranco_Evento_Text_Sergio_6:
@                                                   |
	.string "El caso es que pudimos salir de allí.\n"
	.string "a pesar de llevarnos solo un tercio\l"
	.string "del dinero.\p"
	.string "Dejaremos para más adelante dar\n"
	.string "otro golpe.\p"
	.string "Ahora disfrutemos de nuestro \n"
	.string "reencuentro y de las nuevas\l"
	.string "incorporaciones al equipo.\p"
	.string "¡Podéis presentaros!$"

PisoFranco_Evento_Text_Yuri_1:
	.string "Muy buenas, soy {COLOR DYNAMIC_COLOR5}Yuri{COLOR DARK_GRAY} y soy vecino\n"
	.string "de toda la vida de {COLOR BLUE}Reoneky{COLOR DARK_GRAY}.\p"
	.string "Él me enseñó todo lo que sé\n"
	.string "de hackear habitaciones.\p"
	.string "Soy conocido como el falso RoomHacker\n"
	.string "y rusoworker por excelencia.$"

PisoFranco_Evento_Text_Jack_1:
	.string "Hola, yo soy {COLOR DYNAMIC_COLOR2}Jack Johnson{COLOR DARK_GRAY}\n"
	.string "conocí a {COLOR BLUE}Reoneky{COLOR DARK_GRAY} por un tweet\l"
	.string "de Twitter punto com. Ahora le ayudo a\l"
	.string "hackear habitaciones.$"

PisoFranco_Evento_Text_Sergio_7:
	.string "¡Encantado, bienvenidos al equipo!$"

PisoFranco_Evento_Text_Xiros_1:
@                                                   |
	.string "Grande, {COLOR BLUE}Reoneky{COLOR DARK_GRAY}, buen trabajo\n"
	.string "por traer gente al equipo.\p"
	.string "¡Por lo menos los tuyos se quedan!$"

PisoFranco_Evento_Text_Eing_2:
	.string "¡Eh, eh, eh! ¡Que a mí me han seguido!\n"
	.string "¡Yo no quería!\p"
	.string "Solo me encontré con mi viejo amigo\n"
	.string "{COLOR DYNAMIC_COLOR1}Zein{COLOR DARK_GRAY} y le dije de quedar por los {COLOR RED}loles{COLOR DARK_GRAY}.\p"
	.string "Desde entonces no le he podido\n"
	.string "dar esquinazo.$"

PisoFranco_Evento_Text_Xiros_2:
	.string "Bueno, ya que es {COLOR RED}Nochebuena{COLOR DARK_GRAY}, habrá\n"
	.string "que montar el árbol, ¿no?\p"
	.string "Yo quiero mi {COLOR RED}R{COLOR LIGHT_RED}E{COLOR GREEN}G{COLOR LIGHT_GREEN}A{COLOR BLUE}L{COLOR LIGHT_BLUE}O{COLOR DARK_GRAY}.$"

PisoFranco_Evento_Text_Reonequi_2:
	.string "Yo no digo ná, pero creo que es\n"
	.string "trabajo para {COLOR DYNAMIC_COLOR5}Yuri{COLOR DARK_GRAY}.$"

PisoFranco_Evento_Text_Sergio_8:
	.string "¡Pues ya tienes tu primera tarea!$"

PisoFranco_Evento_Text_Yuri_2:
	.string "{COLOR RED}Joder{COLOR DARK_GRAY}…$"

PisoFranco_Evento_Text_Eing_3:
	.string "¡Ya vas a hacer más que {COLOR LIGHT_GREEN}Pablito{COLOR DARK_GRAY}!$"

PisoFranco_Evento_Text_Yuri_3:
	.string "Bueno, ¡manos a la obra!$"

PisoFranco_Evento_Text_Yuri_4:
	.string "¡Menos mal que he robado este árbol\n"
	.string "del {COLOR RED}Bomberman Tournament{COLOR DARK_GRAY}!$"

PisoFranco_Evento_Text_Yuri_5:
	.string "¡Hale, po' ya'ta!\n¡Con los {COLOR RED}regalos{COLOR DARK_GRAY} y todo!$"

PisoFranco_Evento_Text_Sergio_9:
	.string "Buen trabajo, {COLOR DYNAMIC_COLOR5}Yuri{COLOR DARK_GRAY}.$"

PisoFranco_Evento_Text_Sergio_10:
	.string "Mmm. ¿Qué ha sido eso?$"

PisoFranco_Evento_Text_Sergio_11:
	.string "¡Bah! Seguro que no es nada…$"
