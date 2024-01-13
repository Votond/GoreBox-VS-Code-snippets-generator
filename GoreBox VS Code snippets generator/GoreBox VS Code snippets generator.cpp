#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

char lang;

void userChoose(bool& all, bool& game_data, bool& adv_funcs, bool& objects, bool& events, bool& players, bool& utils);

int main()
{
    setlocale(LC_ALL, "Russian");

    bool all = false;
    bool game_data = false;
    bool adv_funcs = false;
    bool objects = false;
    bool events = false;
    bool players = false;
    bool utils = false;

    ofstream file("generated.txt");
    vector<string> cmds {"OpenConsole", "CloseConsole"};

    system("title GoreBox VS Code extension by Votond");
    cout << "GoreBox VS Code extension by Votond v 1.0\n";

    userChoose(all, game_data, adv_funcs, objects, events, players, utils);

    if (objects || all) {
        cmds.push_back("AddRigidbody");
        cmds.push_back("AddForce(x, y, z, mode)");
        cmds.push_back("SetParent(parent)");
        cmds.push_back("Move(x, y, z)");
        cmds.push_back("MoveLocal(x, y, z)");
        cmds.push_back("SetPosition(x, y, z)");
        cmds.push_back("SetRotation(x, y, z)");
        cmds.push_back("SetLocalRotation(x, y, z)");
        cmds.push_back("Rotate(x, y, z)");
        cmds.push_back("RotateLocal(x, y, z)");
        cmds.push_back("SetScale(x, y, z)");
        cmds.push_back("AddScale(x, y, z)");
    }

    if (events || all) {
        cmds.push_back("ListenForPlayer");
        cmds.push_back("EndListenForPlayer");
        cmds.push_back("EndListenForPlayer");
        cmds.push_back("OnLocalTakeDamage(damage)");
        cmds.push_back("OnLocalDied");
        cmds.push_back("OnLocalInfected");
        cmds.push_back("OnLocalHealed");
        cmds.push_back("OnLocalKnockout");
        cmds.push_back("OnLocalWakeUp");
        cmds.push_back("OnLocalSpawned");
        cmds.push_back("OnLocalRagdoll");
        cmds.push_back("OnLocalGetUp");
        cmds.push_back("OnLocalEmote(emoteName)");
        cmds.push_back("OnLocalEmoteEnd");

        cmds.push_back("ListenForServer");
        cmds.push_back("EndListenForServer");
        cmds.push_back("OnPlayerJoined(player)");
        cmds.push_back("OnPlayerLeft(player)");
        cmds.push_back("OnKilledPlayer(player)");

        cmds.push_back("ListenForChat");
        cmds.push_back("EndListenForChat");
        cmds.push_back("OnChatMessage(sender, message)");

        cmds.push_back("ListenForInventory");
        cmds.push_back("EndListenForInventory");
        cmds.push_back("OnItemSelect(slot)");

        cmds.push_back("ListenForInstantiation");
        cmds.push_back("EndListenForInstantiation");
        cmds.push_back("OnInstantiate(player, name)");

        cmds.push_back("ListenForSceneChange");
        cmds.push_back("EndListenForSceneChange");
        cmds.push_back("OnSceneChanged(sceneName)");

        cmds.push_back("ListenForInput");
        cmds.push_back("EndListenForInput");
        cmds.push_back("OnKeyPress(key)");
        cmds.push_back("OnKeyHold(key)");
        cmds.push_back("OnKeyLift(key)");
    }

    if (objects || all)
    {
        cmds.push_back("SetTexture(name)");
        cmds.push_back("InstantiateEmpty(name, x, y, z, rotX, rotY, rotZ, rotW)");
        cmds.push_back("InstantiateEmptyChild(name, x, y, z, rotX, rotY, rotZ, rotW)");
        cmds.push_back("InstantiateModelChild(model, name, x, y, z, rotX, rotY, rotZ, rotW, scale, collisions, convex)");
        cmds.push_back("InstantiateModel(model, name, x, y, z, rotX, rotY, rotZ, rotW, scale, collisions, convex)");
        cmds.push_back("Instantiate(name, path, x, y, z, rotX, rotY, rotZ, rotW)");
        cmds.push_back("ExecuteScript(target, script)");
        cmds.push_back("ExecuteScriptOnChildren(target, script)");
        cmds.push_back("Destroy(name)");
        cmds.push_back("DestroySelf");
    }

    if (players || all) {
        cmds.push_back("SendChatMessage(sender, message)");
        cmds.push_back("SendChatMessageLocal(sender, message)");
        cmds.push_back("SendErrorMessage(message)");

        cmds.push_back("GiveCurrency(amount)");
        cmds.push_back("RemoveCurrency(amount)");
        cmds.push_back("DropCurrency(amount)");

        cmds.push_back("SetCanDropWeapons(state)");
        cmds.push_back("PlayerHeal");
        cmds.push_back("PlayerKill");
        cmds.push_back("PlayerEmote(emote)");
        cmds.push_back("PlayerEndEmote");
        cmds.push_back("PlayerCripple");
        cmds.push_back("PlayerProtect(duration)");
        cmds.push_back("PlayerSetTeam(team)");
        cmds.push_back("PlayerRagdoll");
        cmds.push_back("PlayerGetUp");
        cmds.push_back("PlayerTeleport(x, y, z)");
        cmds.push_back("PlayerInfect(state)");

        cmds.push_back("GiveItem(name)");
        cmds.push_back("RemoveItem(name)");
    }

    if (utils || all) {
        cmds.push_back("StringContains(string, target)");
        cmds.push_back("RandomInt(min, max)");
        cmds.push_back("RandomFloat(min, max)");
        cmds.push_back("HasRegistered(name)");
        cmds.push_back("HasComponent(componentName)");
    }

    if (objects || all) {
        cmds.push_back("AddAudioSource");
        cmds.push_back("SetAudioLoop(state)");
        cmds.push_back("SetAudioVolume(value)");
        cmds.push_back("SetAudioPitch(value)");
        cmds.push_back("SetAudioSpatial(value)");
        cmds.push_back("SetAudioMinDistance(value)");
        cmds.push_back("SetAudioMaxDistance(value)");
        cmds.push_back("SetAudioClip(name)");
        cmds.push_back("PlayAudioSource");
        cmds.push_back("StopAudioSource");
        cmds.push_back("RemoveAudioSource");

        cmds.push_back("AddAI");
        cmds.push_back("AISetSpeed(value)");
        cmds.push_back("AIFollowTarget(target)");
        cmds.push_back("RemoveAI");

        cmds.push_back("posX");
        cmds.push_back("posY");
        cmds.push_back("posZ");
        cmds.push_back("localPosX");
        cmds.push_back("localPosY");
        cmds.push_back("localPosZ");
        cmds.push_back("rotX");
        cmds.push_back("rotY");
        cmds.push_back("rotZ");
        cmds.push_back("localRotX");
        cmds.push_back("localRotY");
        cmds.push_back("localRotZ");
        cmds.push_back("scaleX");
        cmds.push_back("scaleY");
        cmds.push_back("scaleZ");
        cmds.push_back("childCount");
    }

    if (game_data || all) {
        cmds.push_back("cash");
        cmds.push_back("streak");
        cmds.push_back("streak");
        cmds.push_back("infected");
        cmds.push_back("isHost");
        cmds.push_back("dead");
        cmds.push_back("equippedWeapon");
        cmds.push_back("name");
        cmds.push_back("username");
        cmds.push_back("version");
        cmds.push_back("path");
        cmds.push_back("platform");
        cmds.push_back("targetFrameRate");
        cmds.push_back("gamemode");
    }

    if (utils || all) {
        cmds.push_back("SaveFloat(key, value)");
        cmds.push_back("SaveInt(key, value)");
        cmds.push_back("SaveString(key, value)");
        cmds.push_back("GetFloat(key, defaultValue)");
        cmds.push_back("GetInt(key, defaultValue)");
        cmds.push_back("GetString(key, defaultValue)");
    }

    if (adv_funcs || all) {
        cmds.push_back("AddGamemode(modeName, isHidden, minPlayers, maxPlayers, singleplayer, multiplayer,hostSwitchFeed, playerConnectionFeed, killFeed, hostBadge, hostCommands, hostPerms,canDropWeapons, creator, noclip, invincibility, slowMo, infstamina, infammo, ignoredAI, actionCam,banDolls, banAiDolls, banExplosives, banBigExplosives, banRC, banVehicles, banNextbots, banEntities,banClothes, banMeds, banProps, banFood, banExplosiveWeapons, banHeavyWeapons,banLightWeapons, banMeleeWeapons)");
        cmds.push_back("RegisterGameObject(name, registeredName)");
        cmds.push_back("AddComponent(componentName)");
        cmds.push_back("RemoveComponent(componentName)");
        cmds.push_back("SetComponentValue(componentName, propertyName, value)");
        cmds.push_back("GetComponentStringValue(componentName, propertyName)");
        cmds.push_back("GetComponentFloatValue(componentName, propertyName)");
        cmds.push_back("GetComponentIntValue(componentName, propertyName)");
    }

    if (file.is_open())
    {
        for (string cmd : cmds)
        {
            file << "\"" << cmd << "\": {\n\t\"prefix\": \"" << cmd << "\",\n\t\"body\": [\n\t\t\"" << cmd << "\"\n\t],\n\t\"description\": \"" << cmd << "\"\n},\n";
        }

        file << "\"event listener\": {\n\t\"prefix\": \"elist\",\n\t\"body\" : [\n\t\t\"while true\", \n\t\t\"\\twhile _events.len > 0\", \n\t\t\"\\t\\t_nextEvent = _events.pull\", \n\t\t\"\\t\\t_nextEvent.invoke(_nextEvent.args)\", \n\t\t\"\\tend while\", \n\t\t\"\\tyield\", \n\t\t\"end while\"\n\t], \n\t\"description\" : \"Events listener\"  \n},\n \"command listener\" : {\n\t\"prefix\": \"clist\",\n\t\"body\" : [\n\t\t\"OnChatMessage = function (args)\",\n\t\t\"\\tif message == \\\"?die\\\" then\",\n\t\t\"\\t\\tPlayerKill\", \n\t\t\"\\tend if\", \n\t\t\"end function\"\n], \n\t\"description\" : \"Command listener\"\n}";

        file.close();
    }
    else
    {
        cerr << "An error occurred while opening the file";
    }

    if (lang == 'r')
        cout << "Генерация закончилась. Готовый файл находится рядом с программой";
    else
        cout << "The generation has ended. The finished file is located next to the program";

    cin >> lang;

    return 0;
}

void userChoose(bool& all, bool& game_data, bool& adv_funcs, bool& objects, bool& events, bool& players, bool& utils)
{
    cout << "Choose language. r - russian e - english\n";
    cout << "Выберите язык. r - русский e - английский\n";
    cin >> lang;

    if (lang != 'r' && lang != 'e') {
        userChoose(all, game_data, adv_funcs, objects, events, players, utils);
        return;
    }

    if (lang == 'r')
    {
        char type;

        cout << "Далее используйте только английские алфавит!\nВыберите тип генерации. a - полная (будут сгенерированы все группы) b - выборочная (генерация по выбору)\n";
        cin >> type;

        if (type != 'a' && type != 'b') {
            userChoose(all, game_data, adv_funcs, objects, events, players, utils);
            return;
        }

        if (type == 'a')
        {
            all = true;
        }
        else
        {
            bool next = true;

            while (next)
            {
                char group;

                cout << "Выберите группу. g - игровые данные (cash, streak и т.д.) a - дополненительные функции (AddGamemode, RegisterGameObject и т.д.) o - фунции и данные объекта (Scale, Rotate и т.д.) e - ивенты p - функции и данные игрока u - хранение данных (SaveFloat, GetFloat и т.д.) q - закончить выбор групп\n";
                cin >> group;

                switch (group)
                {
                case 'g':
                    game_data = true;
                    break;

                case 'a':
                    adv_funcs = true;
                    break;

                case 'o':
                    objects = true;
                    break;

                case 'e':
                    events = true;
                    break;

                case 'p':
                    players = true;
                    break;

                case 'u':
                    utils = true;
                    break;

                case 'q':
                    next = false;
                    break;

                default:
                    all = false;
                    game_data = false;
                    adv_funcs = false;
                    objects = false;
                    events = false;
                    players = false;
                    utils = false;
                    userChoose(all, game_data, adv_funcs, objects, events, players, utils);
                    return;
                }
            }
        }

        cout << "Генерация файла \'generated.txt\' началась\n";
    }
    else
    {
        char type;

        cout << "Select the generation type. a - full (all groups will be generated) b - selective (generation by choice)\n";
        cin >> type;

        if (type != 'a' && type != 'b') {
            userChoose(all, game_data, adv_funcs, objects, events, players, utils);
            return;
        }

        if (type == 'a')
        {
            all = true;
        }
        else
        {
            bool next = true;

            while (next)
            {
                char group;

                cout << "Select a group. g - game data (cash, streak, etc.) a - additional functions (AddGamemode, RegisterGameObject, etc.) o - object functions and data (Scale, Rotate, etc.) e - events p - functions and player data u - data storage (SaveFloat, GetFloat, etc.) q - finish selecting groups\n";
                cin >> group;

                switch (group)
                {
                case 'g':
                    game_data = true;
                    break;

                case 'a':
                    adv_funcs = true;
                    break;

                case 'o':
                    objects = true;
                    break;

                case 'e':
                    events = true;
                    break;

                case 'p':
                    players = true;
                    break;

                case 'u':
                    utils = true;
                    break;

                case 'q':
                    next = false;
                    break;

                default:
                    all = false;
                    game_data = false;
                    adv_funcs = false;
                    objects = false;
                    events = false;
                    players = false;
                    utils = false;
                    userChoose(all, game_data, adv_funcs, objects, events, players, utils);
                    return;
                }
            }
        }

        cout << "Generating the \'generated.txt\' file has started\n";
    }
}