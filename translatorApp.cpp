/***************************************************************
 * Name:      translatorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Carlos E. Alfaro Mroales (solrac.azathot@gmail.com)
 * Created:   2018-02-26
 * Copyright: Carlos E. Alfaro Mroales (none)
 * License:   MIT License
 **************************************************************/

#include "translatorApp.h"

//(*AppHeaders
#include "translatorMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(translatorApp);

bool translatorApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    translatorDialog Dlg(0);
    SetTopWindow(&Dlg);
    Dlg.ShowModal();
    wxsOK = false;
    }
    //*)
    return wxsOK;

}
