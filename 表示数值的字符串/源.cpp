#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	system("pause");
	return EXIT_SUCCESS;
}
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return bool布尔型
     */
    bool isNumeric(string str) {
        unordered_map<char, int> map;
        for (int i = 0; i < str.size(); i++)
        {
            if (isdigit(str[i]))
            {
                continue;
            }
            else
            {
                if (str[i] == '.')
                {
                    if (map.count('e') != 0 || map.count('E') != 0) { return false; }
                    if (!map.count(str[i]) && i < str.size() - 1) { map.insert(pair<char, int>(str[i], i)); continue; }
                    else
                    {
                        return false;
                    }
                }
                if (str[i] == 'e' || str[i] == 'E')
                {
                    if (!isdigit(str[i - 1])) { return false; }
                    if (!map.count(str[i]) && i < str.size() - 1) { map.insert(pair<char, int>(str[i], i)); continue; }
                    else
                    {
                        return false;
                    }

                };
                if (str[i] == '+' || str[i] == '-')
                {
                    if (i == str.size() - 1) { return false; }
                    if (i == 0)
                    {
                        continue;
                    }

                    if (map.find('e') != map.end() && map['e'] == i - 1)
                    {
                        continue;
                    }
                    if (map.find('E') != map.end() && map['E'] == i - 1)
                    {
                        continue;
                    }
                    return false;
                }
                return false;
            };

        }
        return true;

    }
};


class Solution {
public:
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL
    };

    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        }
        else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        }
        else if (ch == '.') {
            return CHAR_POINT;
        }
        else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        }
        else if (ch == ' ') {
            return CHAR_SPACE;
        }
        else {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {
                STATE_INITIAL, {
                    {CHAR_SPACE, STATE_INITIAL},
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                    {CHAR_SIGN, STATE_INT_SIGN}
                }
            }, {
                STATE_INT_SIGN, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}
                }
            }, {
                STATE_INTEGER, {
                    {CHAR_NUMBER, STATE_INTEGER},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_POINT, STATE_POINT},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_POINT, {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_POINT_WITHOUT_INT, {
                    {CHAR_NUMBER, STATE_FRACTION}
                }
            }, {
                STATE_FRACTION,
                {
                    {CHAR_NUMBER, STATE_FRACTION},
                    {CHAR_EXP, STATE_EXP},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_EXP,
                {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SIGN, STATE_EXP_SIGN}
                }
            }, {
                STATE_EXP_SIGN, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER}
                }
            }, {
                STATE_EXP_NUMBER, {
                    {CHAR_NUMBER, STATE_EXP_NUMBER},
                    {CHAR_SPACE, STATE_END}
                }
            }, {
                STATE_END, {
                    {CHAR_SPACE, STATE_END}
                }
            }
        };

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++) {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            }
            else {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};