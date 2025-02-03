************************************
************ Cathedral  ************ 
************  Dungeon   ************
************************************

****************
**How it Works**
****************

* The Dungeon is opened in the basement of the Cathedral. Player must be in possession of 1 Black Children of Cathedral Badge and insert this into the false wall door. 
  It will be consumed in the process.

* Once opened a global message will play stating that the Cathedral Basement is open and a timer will countdown from 20 minutes. 

* You will notice that there is a discrepancy of five minutes between the timer countdown end and the time the door will actually close, this is not a mistake. The reason I    
  put this there is that on level 1 there is a risk that NPCs who leave the confines of the dungeon and are killed outside will be trapped on that side if they don`t respawn         
  before the door closes. In Parareal we used dynamic mobs which delete on death and are remade inside the dungeon but here we don`t have this functionality, so this just 
  helps mitigate the risk.

* On level 2 there is a locker which spawn 1 psychic nullifier, which will be needed for level 3, teams will need to bring extra to protect everybody. 

* On level 3 there are a lot of mobs and statted t3/t3.5 in lockers. There is a door behind which the elevator to level 4 is and this door will not open until all mobs, 
  including The Master are dead. 

*To get to the Master, players must pass through The Corridor of Revulsion, they will take significant damage with every step they take in the corridor, but they will take
 none if wearing a psychic nullifier. 

*On level 4 there are two lockers, one will spawn a random implant and the other, a random (unstatted) piece of t4 (if armor, they will get both armor and helm).

*You will notice on the maps that there are no script functions attached to containers, they are not needed as the containers are populated each time the cathedral is opened
 by the "FillContainers" function which is called on opening. This means the place cannot be camped and t4 accumlated by a player hiding inside after the cathedral closes. 
 Mobs will respawn but the loot will not until the next time somebody uses a badge on the door. 

//Updates 2.2.25

*Entire moved in Cathedral main (exiting basement was spawning player in the middle of boxes - player now spawns correctly at top of stairs)
*New mob functions - mobs were previously lootable.
*Master re-made - for some reason BNW dev spammed npc pids with a lot of unnecessary bluesuit/metal armor guards. He is currently untested, may not be tough enough yet. 

******************
**How To Install**
******************

*Copy the map script into scripts file, all maps to the maps file and the "Mutants" file to "proto > critters" (In this file I created The Master critter).

*Everything should plug and play except for a couple of manual edits you`ll need to make to "combat.fos" (below) - just add the things I`ve noted with **>>. This will create
 special NPC roles for humanoids to bypass the `IsTown` FLAG and players will receive experience for killing them. It is necessary, otherwise no experience for killing 
 mutants or humans in the dungeon. You can also use this to add EXP to NPCs in reno sewers and La Grange/Burrows as it is the same problem causing it.   

void ApplyDamage(AttackStruct& attack, Critter& target, uint rounds, bool isCritical, bool intentionally, array<CombatRes>& results, int CriticalChance)
{
	Item@ usedArmor = _GetCritterArmor(target, attack.AimHead);
	
    int      dmgMul = attack.DmgMul;
    int      bt = target.Stat[ST_BODY_TYPE];
 ** add this >> int      IsTownRole = target.Stat[ST_NPC_ROLE]; 
 *****************************************************************************************************************************************************
  if(valid(attacker))
        {
            // OLD VERSION
            /*
            if(bt != BT_MEN && bt != BT_WOMEN && bt != BT_SUPER_MUTANT && bt != BT_GHOUL && bt != BT_CHILDREN && bt != BT_BRAHMIN || !IsTown(map))
                attacker.StatBase[ST_EXPERIENCE] += target.Stat[ST_KILL_EXPERIENCE];
            attacker.KillBase[KILL_BEGIN + bt]++;
            if(target.IsNpc())
                LogExperience(attacker, target.Stat[ST_KILL_EXPERIENCE], valid(realWeapon) ? realWeapon.Proto.Weapon_Skill_0 : SK_UNARMED, "Kill", target.GetProtoId()); // may cause errors with spear
            */
            //_OLD VERSION_

            //_NEW VERSION_
            if(IsTown(map))
            {
 ** Replace with this   >>    if((bt != BT_MEN && bt != BT_WOMEN && bt != BT_SUPER_MUTANT && bt != BT_GHOUL && bt != BT_CHILDREN && bt != BT_BRAHMIN)|| ( IsTownRole == 200 || IsTownRole == 201 || IsTownRole == 202 || IsTownRole == 203)) 
                    attacker.StatBase[ST_EXPERIENCE] += target.Stat[ST_KILL_EXPERIENCE];
			}
***************************************************************************************************************************************************************

