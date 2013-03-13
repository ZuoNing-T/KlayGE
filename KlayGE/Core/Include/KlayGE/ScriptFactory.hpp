/**
 * @file ScriptFactory.hpp
 * @author Minmin Gong
 *
 * @section DESCRIPTION
 *
 * This source file is part of KlayGE
 * For the latest info, see http://www.klayge.org
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * You may alternatively use this source under the terms of
 * the KlayGE Proprietary License (KPL). You can obtained such a license
 * from http://www.klayge.org/licensing/.
 */

#ifndef _SCRIPTFACTORY_HPP
#define _SCRIPTFACTORY_HPP

#pragma once

#include <KlayGE/PreDeclare.hpp>

#include <string>
#include <boost/noncopyable.hpp>

namespace KlayGE
{
	class KLAYGE_CORE_API ScriptFactory
	{
	public:
		virtual ~ScriptFactory()
			{ }

		static ScriptFactoryPtr NullObject();

		virtual std::wstring const & Name() const = 0;
		ScriptEngine& ScriptEngineInstance();

	private:
		virtual ScriptEnginePtr MakeScriptEngine() = 0;

	protected:
		ScriptEnginePtr se_;
	};

	template <typename ScriptEngineType>
	class ConcreteScriptFactory : boost::noncopyable, public ScriptFactory
	{
	public:
		ConcreteScriptFactory(std::wstring const & name)
				: name_(name)
			{ }

		std::wstring const & Name() const
			{ return name_; }

	private:
		ScriptEnginePtr MakeScriptEngine()
		{
			return MakeSharedPtr<ScriptEngineType>();
		}

	private:
		std::wstring const name_;
	};
}

#endif  // _SCRIPTFACTORY_HPP
