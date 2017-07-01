﻿#ifndef __CMODULE_BASE_H__
#define __CMODULE_BASE_H__
#include "GameDefine.h"
#include "Utility/AVLTree.h"
#include "Utility/Position.h"

class CPlayerObject;

class CModuleBase
{
public:
	CModuleBase(CPlayerObject *pOwner);

	~CModuleBase();

	virtual BOOL OnCreate(UINT64 u64RoleID) = 0;

	virtual BOOL OnDestroy(UINT64 u64RoleID) = 0;

	virtual BOOL OnLogin(UINT64 u64RoleID) = 0;

	virtual BOOL OnLogout(UINT64 u64RoleID) = 0;

	virtual BOOL OnNewDay() = 0;

	virtual BOOL OnLoadData(UINT64 u64RoleID) = 0;

	virtual BOOL IsDataOK();

	virtual BOOL SetDataOK(BOOL bOK);

	virtual BOOL DispatchPacket(NetPacket *pNetPack);

	BOOL SetOwner(CPlayerObject *pOwner);

	CPlayerObject* GetOwner();

public:
	CPlayerObject *m_pOwnPlayer;
	BOOL		   m_bIsDataOK;
};


#endif //__CMODULE_BASE_H__
