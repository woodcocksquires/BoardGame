/*
 * APIUtility.h
 *
 *  Created on: 10 Jun 2014
 *      Author: Andrew.squires
 */

#ifndef APIUTILITY_H_
#define APIUTILITY_H_

#include<string>
#include<lua.hpp>

using namespace std;

namespace Wsq {
	namespace Lua {
		struct EmptyTable {};

		class NotALuaTableException: public exception{
			virtual const char * what() const throw(){
				return "The requested path is not a Lua table";
			}
		};

		class LuaFieldIsNilException: public exception{
			virtual const char * what() const throw(){
				return "The requested field returned nil";
			}
		};

		class BadLuaFieldCastException: public exception{
			virtual const char * what() const throw(){
				return "The requested field value was not of the requested type";
			}
		};

		class APIUtility {
		  private:
			static APIUtility * _APIUtility;

			lua_State * _luaState;
			bool GetTable(string name);
			int GetTablePath(string path);

			APIUtility();
			~APIUtility();
		  public:
			static APIUtility * GetUtility();

			int LoadAndExecuteFile(string path);
			int GetField(string path);
			bool GlobalExists(string name);
			bool FieldExists(string name);

			void SetGlobal(string name, bool value);
			void SetGlobal(string name, bool value, bool keepOnStack);
			void SetGlobal(string name, double value);
			void SetGlobal(string name, double value, bool keepOnStack);
			void SetGlobal(string name, char * value);
			void SetGlobal(string name, char * value, bool keepOnStack);
			void SetGlobal(string name, EmptyTable value);
			void SetGlobal(string name, EmptyTable value, bool keepOnStack);
			void SetGlobal(string name, int value);
			void SetGlobal(string name, int value, bool keepOnStack);

			void SetField(string name, bool value);
			void SetField(string name, int value);
			void SetField(string name, double value);
			void SetField(string name, char * value);
			void SetField(string name, string value);
			void SetField(string name, EmptyTable value);
			void SetField(string name, bool value, bool keepOnStack);
			void SetField(string name, int value, bool keepOnStack);
			void SetField(string name, double value, bool keepOnStack);
			void SetField(string name, char * value, bool keepOnStack);
			void SetField(string name, string value, bool keepOnStack);
			void SetField(string name, EmptyTable value, bool keepOnStack);

			bool FieldToBool(string path);
			int FieldToInt(string path);
			double FieldToDouble(string path);
			string FieldToString(string path);
		};
	}
}



#endif /* APIUTILITY_H_ */
