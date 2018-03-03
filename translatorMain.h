/***************************************************************
 * Name:      translatorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Carlos E. Alfaro Mroales (solrac.azathot@gmail.com)
 * Created:   2018-02-26
 * Copyright: Carlos E. Alfaro Mroales (none)
 * License:   MIT License
 **************************************************************/

#ifndef TRANSLATORMAIN_H
#define TRANSLATORMAIN_H

//(*Headers(translatorDialog)
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
//*)

#include "engine.hpp"

class translatorDialog: public wxDialog
{
    public:

        translatorDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~translatorDialog();

    private:

        //(*Handlers(translatorDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTranslate(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        //*)

        //(*Identifiers(translatorDialog)
        static const long ID_CHOICE1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_CHOICE2;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON3;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON4;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(translatorDialog)
        wxBoxSizer* BoxSizer3;
        wxButton* Button4;
        wxButton* Button1;
        wxButton* Button2;
        wxTextCtrl* tctrlOutput;
        wxButton* Button3;
        wxBoxSizer* BoxSizer2;
        wxStaticLine* StaticLine1;
        wxBoxSizer* BoxSizer4;
        wxChoice* chcFrom;
        wxBoxSizer* BoxSizer1;
        wxTextCtrl* tctrlInput;
        wxChoice* chcTo;
        wxBitmapButton* BitmapButton1;
        //*)

        Engine engine_;

        DECLARE_EVENT_TABLE()
};

#endif // TRANSLATORMAIN_H
