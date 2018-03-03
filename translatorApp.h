/***************************************************************
 * Name:      translatorApp.h
 * Purpose:   Defines Application Class
 * Author:    Carlos E. Alfaro Mroales (solrac.azathot@gmail.com)
 * Created:   2018-02-26
 * Copyright: Carlos E. Alfaro Mroales (none)
 * License:   MIT License
 **************************************************************/

#ifndef TRANSLATORAPP_H
#define TRANSLATORAPP_H

#include <wx/app.h>

class translatorApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // TRANSLATORAPP_H
