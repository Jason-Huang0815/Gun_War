/**
 * @file GameRules.h
 * @author 反六王联盟盟主
 * @date 2026/9/4
 * @brief the only reasonable file to change the state
 */

#ifndef GUNWAR_GAMERULES_H
#define GUNWAR_GAMERULES_H


class GameRules {
public:
    static void CheckLoseCondition();

    static void CheckWinCondition();
};


#endif //GUNWAR_GAMERULES_H
