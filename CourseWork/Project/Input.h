#pragma once

enum eDirection { STOP = 0, LEFT, RIGTH, UP, DOWN };
static eDirection dir;
enum eDone { NONE = 0, DONE };
static eDone done;

void Input(bool&, bool&);
void ResetInput();
eDirection GetDir();
eDone GetDone();