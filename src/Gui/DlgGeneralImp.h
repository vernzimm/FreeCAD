/***************************************************************************
 *   Copyright (c) 2004 Werner Mayer <wmayer[at]users.sourceforge.net>     *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/


#ifndef GUI_DIALOG_DLGGENERALIMP_H
#define GUI_DIALOG_DLGGENERALIMP_H

#include "PropertyPage.h"
#include <memory>

class QTabWidget;

namespace Gui {
namespace Dialog {
class Ui_DlgGeneral;
class DlgCreateNewPreferencePackImp;
class DlgPreferencePackManagementImp;
class DlgRevertToBackupConfigImp;

/** This class implements the settings for the application.
 *  You can change window style, size of pixmaps, size of recent file list and so on
 *  \author Werner Mayer
 */
class DlgGeneralImp : public PreferencePage
{
    Q_OBJECT

public:
    explicit DlgGeneralImp( QWidget* parent = nullptr );
    ~DlgGeneralImp() override;

    void saveSettings() override;
    void loadSettings() override;

protected:
    void changeEvent(QEvent *event) override;

protected Q_SLOTS:
    void onLoadPreferencePackClicked(const std::string &packName);
    void recreatePreferencePackMenu();
    void newPreferencePackDialogAccepted();
    void onManagePreferencePacksClicked();
    void onImportConfigClicked();

private:
    void setRecentFileSize();
    void saveAsNewPreferencePack();
    void revertToSavedConfig();
    bool setLanguage(); //Returns true if language has been changed
    void setNumberLocale(bool force = false);
    void setDecimalPointConversion(bool on);

private:
    int localeIndex;
    std::unique_ptr<Ui_DlgGeneral> ui;
    std::unique_ptr<DlgCreateNewPreferencePackImp> newPreferencePackDialog;
    std::unique_ptr<DlgPreferencePackManagementImp> preferencePackManagementDialog;
    std::unique_ptr<DlgRevertToBackupConfigImp> revertToBackupConfigDialog;
};

} // namespace Dialog
} // namespace Gui

#endif // GUI_DIALOG_DLGGENERALIMP_H
