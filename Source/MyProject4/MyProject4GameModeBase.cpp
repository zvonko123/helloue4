// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject4.h"
#include "MyProject4GameModeBase.h"
#include "MyPlayer.h"

AMyProject4GameModeBase::AMyProject4GameModeBase()
{
// set default pawn class to our ball
DefaultPawnClass = AMyPlayer::StaticClass();
}


