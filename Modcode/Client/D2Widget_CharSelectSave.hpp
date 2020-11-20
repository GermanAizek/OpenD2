#pragma once
#include "D2Widget.hpp"

#define D2_NUM_VISIBLE_SAVES	8

/**
 *	D2Widget_CharSelectSave is contained within a D2Widget_CharSelectList.
 *	It's a linked list of elements to draw.
 */
class D2Widget_CharSelectSave : public D2Widget
{
private:
	D2Widget_CharSelectSave* nextInChain;
	char16_t charName[32];
	char16_t charClassAndLevel[32];
	char path[MAX_D2PATH_ABSOLUTE];
	bool bIsSelected, bHasTitle, bIsDeadHardcore, bIsExpansion, bIsHardcore;
	D2SaveHeader saveHeader;
	ITokenReference* token;

	const int nSlotWidth = 272;
	const int nSlotHeight = 93;

	void OnSelected();

	IRenderObject* selectionFrame;
	IRenderObject* characterPreview;
	IRenderObject* characterTitle;
	IRenderObject* characterName;
	IRenderObject* characterLevelAndClass;
	IRenderObject* expansionText;
	IRenderObject* characterRender;

public:
	D2Widget_CharSelectSave(const char* characterSave, D2SaveHeader& header);
	virtual ~D2Widget_CharSelectSave();

	void SetDrawPosition(uint32_t x, uint32_t y);

	virtual void Draw();
	
	bool CheckMouseDownInChain(DWORD dwX, DWORD dwY, int& counter);
	bool CheckMouseClickInChain(DWORD dwX, DWORD dwY, int& counter);

	virtual bool HandleMouseDown(DWORD dwX, DWORD dwY) { return false; }
	virtual bool HandleMouseClick(DWORD dwX, DWORD dwY) { return false; }
	
	void SetNextInChain(D2Widget_CharSelectSave* next);
	void DrawLink(int counter, bool bDrawLeft);
	D2Widget_CharSelectSave* GetInChain(int counter);
	void Select(int counter);
	void DeselectAllInChain();

	char16_t* GetSelectedCharacterName();
};