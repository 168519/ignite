/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _IGNITE_ODBC_SYSTEM_UI_DSN_CONFIGURATION_WINDOW
#define _IGNITE_ODBC_SYSTEM_UI_DSN_CONFIGURATION_WINDOW

#include "ignite/odbc/config/configuration.h"
#include "ignite/odbc/system/ui/custom_window.h"

namespace ignite
{
    namespace odbc
    {
        namespace system
        {
            namespace ui
            {
                /**
                 * DSN configuration window class.
                 */
                class DsnConfigurationWindow : public CustomWindow
                {
                    /**
                     * Children windows ids.
                     */
                    enum ChildId
                    {
                        ID_CONNECTION_SETTINGS_GROUP_BOX,
                        ID_NAME_EDIT,
                        ID_NAME_LABEL,
                        ID_ADDRESS_EDIT,
                        ID_ADDRESS_LABEL,
                        ID_CACHE_EDIT,
                        ID_CACHE_LABEL,
                        ID_OK_BUTTON,
                        ID_CANCEL_BUTTON
                    };

                public:
                    /**
                     * Constructor.
                     *
                     * @param parent Parent window handle.
                     */
                    explicit DsnConfigurationWindow(Window* parent, config::Configuration& config);

                    /**
                     * Destructor.
                     */
                    virtual ~DsnConfigurationWindow();

                    /**
                     * Create window in the center of the parent window.
                     */
                    void Create();

                    /**
                    * @copedoc ignite::odbc::system::ui::CustomWindow::OnCreate
                    */
                    virtual void OnCreate();

                    /**
                     * @copedoc ignite::odbc::system::ui::CustomWindow::OnMessage
                     */
                    virtual bool OnMessage(UINT msg, WPARAM wParam, LPARAM lParam);

                private:
                    IGNITE_NO_COPY_ASSIGNMENT(DsnConfigurationWindow)

                    /**
                     * Retrieves current values from the children and stores
                     * them to the specified configuration.
                     *
                     * @param cfg Configuration.
                     */
                    void RetrieveParameters(config::Configuration& cfg) const;

                    /** Window width. */
                    int width;

                    /** Window height. */
                    int height;

                    /** Connection settings group box. */
                    std::auto_ptr<Window> connectionSettingsGroupBox;

                    /** DSN name edit field label. */
                    std::auto_ptr<Window> nameLabel;

                    /** DSN name edit field. */
                    std::auto_ptr<Window> nameEdit;

                    /** DSN address edit field label. */
                    std::auto_ptr<Window> addressLabel;

                    /** DSN address edit field. */
                    std::auto_ptr<Window> addressEdit;

                    /** DSN cache edit field label. */
                    std::auto_ptr<Window> cacheLabel;

                    /** DSN cache edit field. */
                    std::auto_ptr<Window> cacheEdit;

                    /** Ok button. */
                    std::auto_ptr<Window> okButton;

                    /** Cancel button. */
                    std::auto_ptr<Window> cancelButton;

                    /** Configuration. */
                    config::Configuration& config;

                    /** Flag indicating whether OK option was selected. */
                    bool accepted;
                };
            }
        }
    }
}

#endif //_IGNITE_ODBC_SYSTEM_UI_DSN_CONFIGURATION_WINDOW