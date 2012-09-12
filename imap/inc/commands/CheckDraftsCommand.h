// @@@LICENSE
//
//      Copyright (c) 2010-2012 Hewlett-Packard Development Company, L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// LICENSE@@@

#ifndef CHECKDRAFTSCOMMAND_H_
#define CHECKDRAFTSCOMMAND_H_

#include "commands/ImapClientCommand.h"
#include "db/MojDbClient.h"
#include "activity/Activity.h"

class CheckDraftsCommand : public ImapClientCommand
{
public:
	CheckDraftsCommand(ImapClient& client, const ActivityPtr& activity);
	virtual ~CheckDraftsCommand();

protected:
	virtual void RunImpl();

	void GetDrafts();
	MojErr GetDraftsResponse(MojObject& response, MojErr err);

	ActivityPtr m_activity;

	MojDbQuery::Page m_draftsPage;

	MojDbClient::Signal::Slot<CheckDraftsCommand>	m_getDraftsSlot;
};

#endif /* CHECKDRAFTSCOMMAND_H_ */