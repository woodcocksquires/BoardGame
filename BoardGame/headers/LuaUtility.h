#ifndef LUAUTILTIY_H_
#define LUAUTILITY_H_

#include <string>
#include <lua.hpp>
#include <exception>

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

		class LuaUtility {
		private:
			static bool GetTable(lua_State * L, string name);
			static int GetTablePath(lua_State * L, string path);
		  public:
			static lua_State * GetNewState();
			static int LoadAndExecuteFile(lua_State * L, string path);
			static void CloseState(lua_State * L);
			static bool GlobalExists(lua_State * L, string name);
			static bool FieldExists(lua_State * L, string name);
			static int GetField(lua_State * L, string path);
			static void SetGlobal(lua_State * L, string name, bool value);
			static void SetGlobal(lua_State * L, string name, int value);
			static void SetGlobal(lua_State * L, string name, double value);
			static void SetGlobal(lua_State * L, string name, char * value);
			static void SetGlobal(lua_State * L, string name, string value);
			static void SetGlobal(lua_State * L, string name, EmptyTable value);
			static void SetGlobal(lua_State * L, string name, bool value, bool keepOnStack);
			static void SetGlobal(lua_State * L, string name, int value, bool keepOnStack);
			static void SetGlobal(lua_State * L, string name, double value, bool keepOnStack);
			static void SetGlobal(lua_State * L, string name, char * value, bool keepOnStack);
			static void SetGlobal(lua_State * L, string name, string value, bool keepOnStack);
			static void SetGlobal(lua_State * L, string name, EmptyTable value, bool keepOnStack);
			static void SetField(lua_State * L, string name, bool value);
			static void SetField(lua_State * L, string name, int value);
			static void SetField(lua_State * L, string name, double value);
			static void SetField(lua_State * L, string name, char * value);
			static void SetField(lua_State * L, string name, string value);
			static void SetField(lua_State * L, string name, EmptyTable value);
			static void SetField(lua_State * L, string name, bool value, bool keepOnStack);
			static void SetField(lua_State * L, string name, int value, bool keepOnStack);
			static void SetField(lua_State * L, string name, double value, bool keepOnStack);
			static void SetField(lua_State * L, string name, char * value, bool keepOnStack);
			static void SetField(lua_State * L, string name, string value, bool keepOnStack);
			static void SetField(lua_State * L, string name, EmptyTable value, bool keepOnStack);
			static bool FieldToBool(lua_State * L, string path);
			static int FieldToInt(lua_State * L, string path);
			static double FieldToDouble(lua_State * L, string path);
			static string FieldToString(lua_State * L, string path);
		};
	}
}

#endif
