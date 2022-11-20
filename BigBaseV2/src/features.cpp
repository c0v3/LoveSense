#include "common.hpp"
#include "features.hpp"
#include "logger.hpp"
#include "natives.hpp"
#include "script.hpp"
#include <gta/enums.hpp>
#include <pointers.hpp>

namespace big
{

	bool padcheck(int padindex) {
		return PAD::IS_CONTROL_PRESSED(0, padindex);
	}



	void features::run_tick()
	{
		if (TOGGLES.explosion_monitor_toggle) {

			//for (int i = 0; i < sizeof(ExplosionTypes); i++) {

				Vector3 player = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(),false);

			/*	if (FIRE::IS_EXPLOSION_ACTIVE_IN_AREA(-1, player.x, player.y, player.z, 1000, 1000, 1000)) {
				//	LOG(INFO) << "explosion of type" << i << "Detected" << ExplosionTypes(i);
					LOG(INFO) << "explosion detected";
				}*/
				if (FIRE::IS_EXPLOSION_IN_SPHERE(-1, player.x, player.y, player.z, 1000.f)) {
					LOG(INFO) << "explosion detected";

				}


			//}


		}

		if (TOGGLES.controlls_monitor_toggle) {

		
			//LOG(INFO) << "test:" << &g_pointers->control_shake_result;



			for (int i = 0; i < sizeof(ControllerInputs); i++) {


				if (padcheck(i)) {
					LOG(INFO) << "Pad press of type" << i << "Detected" << ControllerInputs(i);
				}

			}


		}



		if (control_test_toggle) {

			// vibration inputs 


			if (PAD::IS_CONTROL_PRESSED(0,86)) {//vehicle horn
				
				LOG(INFO) << "horn pressed";
			}
			if (PAD::IS_CONTROL_PRESSED(0, 0)) {//INPUT_NEXT_CAMERA
				LOG(INFO) << "horn pressed";
			}


			//PAD::SET_PAD_SHAKE(0, 1000, 200);

			/*

			This is mostly guessing/random testing but im quite sure these are most of the stuff that casuses vibrate by default + extras


	3	INPUT_LOOK_UP_ONLY
	4 INPUT_LOOK_DOWN_ONLY
			5 INPUT_LOOK_LEFT_ONLY
			6 INPUT_LOOK_RIGHT_ONLY

			8 INPUT_SCRIPTED_FLY_UD
			 9 INPUT_SCRIPTED_FLY_LR
			10 INPUT_SCRIPTED_FLY_ZUP
			11 INPUT_SCRIPTED_FLY_ZDOWN
		12	INPUT_WEAPON_WHEEL_UD
		13	INPUT_WEAPON_WHEEL_LR
		14	INPUT_WEAPON_WHEEL_NEXT
		15	INPUT_WEAPON_WHEEL_PREV
		16	INPUT_SELECT_NEXT_WEAPON
		17	INPUT_SELECT_PREV_WEAPON
		18	INPUT_CHARACTER_WHEEL
		19	INPUT_MULTIPLAYER_INFO

		21	INPUT_SPRINT
		22	INPUT_JUMP
		23	INPUT_ENTER
		24	INPUT_ATTACK
		25	INPUT_AIM
		26	INPUT_LOOK_BEHIND
		27	INPUT_PHONE

		32	INPUT_MOVE_UP_ONLY	W	LEFT STICK
		33	INPUT_MOVE_DOWN_ONLY	S	LEFT STICK
		34	INPUT_MOVE_LEFT_ONLY	A	LEFT STICK
		35	INPUT_MOVE_RIGHT_ONLY	D	LEFT STICK
		36	INPUT_DUCK	LEFT CTRL	L3
		37	INPUT_SELECT_WEAPON	TAB	LB
		38	INPUT_PICKUP	E	LB





			*/


		}


	}

	void features::script_func()
	{
		while (true)
		{
			TRY_CLAUSE
			{
				run_tick();
			}
			EXCEPT_CLAUSE
			script::get_current()->yield();
		}
	}
}
