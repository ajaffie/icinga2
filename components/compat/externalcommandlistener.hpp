/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012-2014 Icinga Development Team (http://www.icinga.org)    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#ifndef EXTERNALCOMMANDLISTENER_H
#define EXTERNALCOMMANDLISTENER_H

#include "compat/externalcommandlistener.thpp"
#include "base/objectlock.hpp"
#include "base/timer.hpp"
#include "base/utility.hpp"
#include <boost/thread/thread.hpp>
#include <iostream>

namespace icinga
{

/**
 * @ingroup compat
 */
class ExternalCommandListener : public ObjectImpl<ExternalCommandListener>
{
public:
	DECLARE_PTR_TYPEDEFS(ExternalCommandListener);
	DECLARE_TYPENAME(ExternalCommandListener);

	static Value StatsFunc(Dictionary::Ptr& status, Dictionary::Ptr& perfdata);

protected:
	virtual void Start(void);

private:
#ifndef _WIN32
	boost::thread m_CommandThread;

	void CommandPipeThread(const String& commandPath);
	void ClientHandler(const String& commandPath, int fd);
#endif /* _WIN32 */
};

}

#endif /* EXTERNALCOMMANDLISTENER_H */
