#ifndef __UILANGUAGEMANAGER_H__
#define __UILANGUAGEMANAGER_H__
#pragma once

namespace DuiLib {
	class UILIB_API CLangPackageUI
	{
	public:
		CLangPackageUI();
		~CLangPackageUI();
	
	public:
		void SetSkinFile(LPCTSTR lpstrSkinFile);
		LPCTSTR GetSkinFile();
		BOOL LoadResource(STRINGorID xml, LPCTSTR type);
		BOOL LoadResource(CMarkupNode Root);
		void ResetResource();

		BOOL AddText(int resid, LPCTSTR lpstrText);
		LPCTSTR GetText(int resid);
		BOOL AddText(CDuiString resId, LPCTSTR lpstrText);
		LPCTSTR GetText(CDuiString resid);

		BOOL AddToolTip(int resid, LPCTSTR lpstrText);
		LPCTSTR GetToolTip(int resid);
		BOOL AddToolTip(CDuiString resid, LPCTSTR lpstrText);
		LPCTSTR GetToolTip(CDuiString resid);

		BOOL AddTipValue(int resid, LPCTSTR lpstrText);
		LPCTSTR GetTipValue(int resid);
		BOOL AddTipValue(CDuiString resid, LPCTSTR lpstrText);
		LPCTSTR GetTipValue(CDuiString resid);

	private:
		CDuiString m_sSkinFile;

		std::map<CDuiString*, CDuiString*, CDuiStringMapCompare> m_mText;
		std::map<CDuiString*, CDuiString*, CDuiStringMapCompare> m_mToolTip;
		std::map<CDuiString*, CDuiString*, CDuiStringMapCompare> m_mTipValue;
	private:
	};

	class UILIB_API CLangManagerUI
	{
	protected:
		struct tagStringTable 
		{
			CDuiString id;
			CDuiString text1;
			CDuiString text2;
		};
	public:
		CLangManagerUI(void);
		~CLangManagerUI(void);

		void ReloadLanguage();
		CLangPackageUI *AddPackage(LPCTSTR lpstrSkinFile);
		CLangPackageUI *GetPackage(LPCTSTR lpstrSkinFile);
	
		static void SetLanguage(LPCTSTR lpstrPath, LPCTSTR lpstrname); //设置语言包文件夹
		static CDuiString GetLangPath();
		static CDuiString GetLangName();

		static void ReleaseStringTable();
		static LPCTSTR GetString(int id, LPCTSTR defaultstring = NULL);
		static LPCTSTR GetStringExtra(int id, LPCTSTR defaultstring = NULL);
		static LPCTSTR GetString(CDuiString id, LPCTSTR defaultstring = NULL);
		static LPCTSTR GetStringExtra(CDuiString id, LPCTSTR defaultstring = NULL);
	protected:
		void ResetPackage();
		CLangPackageUI *_addPackage(LPCTSTR lpstrSkinFile);
		static BOOL LoadStringTable();
		static BOOL LoadStringTableResource(STRINGorID xml, LPCTSTR type);
		static BOOL LoadStringTableResource(CMarkupNode Root);
	private:
		CStdStringPtrMap m_mLangPackage;	//LangPackage
		CStdStringPtrMap m_mSkinFile;		//所有已加载的xml
		static CDuiString s_sLangPath;
		static CDuiString s_sLangName;
		static std::map<CDuiString, tagStringTable *> m_mStringTable;
	};

} // namespace DuiLib

#endif // __UILANGUAGEMANAGER_H__