//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : debuggerpane.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
 #ifndef DEBUGGERPANE_H
#define DEBUGGERPANE_H

#include "wx/panel.h"
#include "notebook_ex.h"
#include <wx/imaglist.h>

class ListCtrlPanel;
class LocalsTable;
class WatchesTable;
class BreakpointDlg;
class ThreadListPanel;
class MemoryView;
class wxAuiManager;
class DebuggerAsciiViewer;
class DebugTab;

class DebuggerPane : public wxPanel
{
public:
	static const wxString LOCALS;
	static const wxString WATCHES;
	static const wxString FRAMES;
	static const wxString BREAKPOINTS;
	static const wxString THREADS;
	static const wxString MEMORY;
	static const wxString ASCII_VIEWER;
	static const wxString DEBUGGER_OUTPUT;
	
private:
	Notebook *            m_book;
	LocalsTable *         m_localsTable;
	wxString              m_caption;
	WatchesTable *        m_watchesTable;
	ListCtrlPanel *       m_frameList;
	BreakpointDlg *       m_breakpoints;
	ThreadListPanel*      m_threads;
	MemoryView *          m_memory;
	DebuggerAsciiViewer*  m_asciiViewer;
	bool                  m_initDone;
	wxAuiManager *        m_mgr;
	DebugTab*             m_outputDebug;
	
private:
	void CreateGUIControls();

public:
	DebuggerPane(wxWindow *parent, const wxString &caption, wxAuiManager *mgr);
	virtual ~DebuggerPane();

	//setters/getters
	const wxString &     GetCaption       () const{return m_caption;}
	LocalsTable *        GetLocalsTable   () { return m_localsTable;}
	WatchesTable *       GetWatchesTable  () { return m_watchesTable;}
	ListCtrlPanel *      GetFrameListView () { return m_frameList;}
	BreakpointDlg *      GetBreakpointView() { return m_breakpoints;}
	ThreadListPanel *    GetThreadsView   () { return m_threads;}
	MemoryView *         GetMemoryView    () { return m_memory;}
	DebuggerAsciiViewer* GetAsciiViewer   () { return m_asciiViewer;}
	DebugTab*            GetDebugWindow   () { return m_outputDebug;}

	Notebook *GetNotebook(){return m_book;}
	void SelectTab(const wxString &tabName);
	void Clear();

	DECLARE_EVENT_TABLE()
	void OnPageChanged(NotebookEvent &event);
};
#endif //DEBUGGERPANE_H

