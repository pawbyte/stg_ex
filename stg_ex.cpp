/*
stg_ex.cpp
This file is part of:
stg_ex
https://pawbyte.com/opensource
Copyright (c) 2014-2020 Nathan Hurde, Chase Lee.

Copyright (c) 2014-2020 PawByte LLC.
Copyright (c) 2014-2020 Game Pencil Engine contributors ( Contributors Page )

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-stg_ex <https://pawbyte.com/opensource>


*/

#include "stg_ex.h"

namespace stg_ex
{
    bool char_is_alnum(char c, bool allowSpaces, bool allowUnderscores)
    {
        if( allowSpaces && c == ' ')
        {
            return true;
        }
        if( allowUnderscores && c == '_')
        {
            return true;
        }
        return isalnum(c);
    }

    bool char_is_alpha(char c, bool allowSpaces, bool allowUnderscores)
    {
        if( allowSpaces && c == ' ')
        {
            return true;
        }
        if( allowUnderscores && c == '_')
        {
            return true;
        }
        return isalpha(c);
    }

    bool is_alnum(const std::string str, bool allowSpaces, bool allowUnderscores)
    {
        int strSize = (int)str.size();
        bool validCharacterFound = true;
        if( strSize >0)
        {
            if( isalpha(str[0]) )
            {
                int i = 1;
                while( i < strSize && validCharacterFound)
                {
                    validCharacterFound = char_is_alnum(str[i], allowSpaces, allowUnderscores );
                    i++;
                }
                return validCharacterFound;
            }
        }
        return false;
    }

    std::vector <std::string> divide_string_into_lines(std::string stringIn,int numbLines)
    {
        std::vector <std::string> returnVector;
        /*
        int wholeLength= stringIn.size();
        if(numbLines>0)
        {
             int maxLengthForString = wholeLength/numbLines;
             for(int ii=0;ii<numbLines;ii+=1)
             {

                  //divides the string into multiple two pieces
                  std::string line_text_xx=stringIn.substr((i*maxLengthForString),(i+1)*maxLengthForString);
                  std::string new_text_n=stringIn.substr((i*maxLengthForString),line_text_x.size()-(i*maxLengthForString));
                  //checks for the first character in the string of both old and new
                  std::string firstForNew=new_text_n.substr(0,1);
                  std::string firstForNew2 = string_letters(firstForNew);
                  std::string lastForOld = line_text_xx.substr(line_text_xx.size(),1);
                  std::string lastForOld2= string_letters(lastForOld);
                  //if a problem arises like the ending character not being empty, we add a dash to the string being inserted
                  if( (firstForNew.compare(" ")==0)&&(lastForOld.compare("")==0)&&(firstForNew.compare(firstForNew2) )&&(lastForOld.compare(lastForOld2) ))
                  {
                       //adds a dash to the string and adds it to our vector
                       returnVector.push_back(line_text_xx.append("-"));
                  }
                  else
                  {
                       //lovely we have a space, thus we just add it as planned.
                       returnVector.push_back(line_text_xx);
                  }
             }
        }
        else
        {
            returnVector.push_back(stringIn);
        }
        */
        return returnVector;
    }

    std::string double_to_string(double in)
    {
        std::ostringstream converter;
        converter << in;
        return converter.str();
    }

    bool file_is_audio(std::string fileLocationIn)
    {
        std::string foundExt = get_file_ext(fileLocationIn);
        if( foundExt=="aac" || foundExt=="mp3"  || foundExt=="ogg"  || foundExt=="wav" )
        {
            return true;
        }
        return false;
    }

    bool file_is_font(std::string fileLocationIn)
    {
        std::string foundExt = get_file_ext(fileLocationIn);
        if( foundExt=="eot" || foundExt=="svg"  || foundExt=="ttf"  || foundExt=="woff" || foundExt=="woff2" )
        {
            return true;
        }
        return false;
    }

    bool file_is_image(std::string fileLocationIn)
    {
        std::string foundExt = get_file_ext(fileLocationIn);
        if( foundExt=="bmp" || foundExt=="gif"  ||foundExt=="jpg"  || foundExt=="jpeg"  || foundExt=="png" )
        {
            return true;
        }
        return false;
    }

    bool file_is_video(std::string fileLocationIn)
    {
        std::string foundExt = get_file_ext(fileLocationIn);
        if( foundExt=="mp4" || foundExt=="ogg" || foundExt=="webm" )
        {
            return true;
        }
        return false;
    }

    std::string file_to_dir(std::string fileNameIn)
    {
        if(!fileNameIn.empty())
        {

            return fileNameIn.substr(0,fileNameIn.find(".") );
        }
        else
        {
            return "";
        }
        return fileNameIn;
    }

    std::string float_to_string(float in)
    {
        std::ostringstream converter;
        converter << in;
        return converter.str();
    }

    //returns the inputed value with 2 digits each time
    std::string get_2digit_value_string(int numberIn)
    {
        if(numberIn<10)
        {
            std::stringstream tempText;
            tempText << "0" << int_to_string(numberIn);
            return tempText.str();
        }
        else
        {
            return int_to_string(numberIn);
        }
    }

    std::string get_file_ext(std::string fileLocationIn)
    {
        if( (int)fileLocationIn.size() > 0)
        {
            int dotPos = fileLocationIn.find_first_of(".");
            if(dotPos != (int)std::string::npos)
            {
                return fileLocationIn.substr( dotPos+ 1);
            }
        }
        return "";
    }

    std::string get_file_ext_last_dot(std::string fileLocationIn)
    {
        if( (int)fileLocationIn.size() > 0)
        {
            int dotPos = fileLocationIn.find_last_of(".");
            if(dotPos != (int)std::string::npos)
            {
                return fileLocationIn.substr( dotPos+ 1);
            }
        }
        return "";
    }

    std::string get_file_noext(std::string fileLocationIn)
    {
        if( fileLocationIn.size() > 0)
        {
            int dotPos = fileLocationIn.find_first_of(".");
            if(dotPos != (int)std::string::npos)
            {
                return fileLocationIn.substr( 0,dotPos);
            }
            else
            {
                return fileLocationIn;
            }
        }
        return "";
    }
    std::string get_local_from_global_file(std::string fullFilePath)
    {
        if( fullFilePath.size()>0)
        {
            size_t found;
            found=fullFilePath.find_last_of("/\\");
            if( found != std::string::npos)
            {
                std::string dString = fullFilePath.substr(0,found);
                std::string rString = fullFilePath.substr(found+1);
                return rString;
            }
        }
        return fullFilePath;
    }

    std::string get_path_from_file(std::string fullFilePath)
    {
        if( fullFilePath.size()>0)
        {
            size_t found;
            found=fullFilePath.find_last_of("/\\");
            if( found != std::string::npos)
            {
                std::string rString = fullFilePath.substr(0,found);
                return rString+"\\";
            }
        }
        return fullFilePath;
    }

    std::string get_short_filename(std::string fileNameIn,bool showExtension)
    {
        if(!fileNameIn.empty())
        {
            if(showExtension)
            {
                return fileNameIn.substr(fileNameIn.find_last_of("\\/") +1);
            }
            else
            {
                return fileNameIn.substr(fileNameIn.find_last_of("\\/")+1,fileNameIn.find(".") );
            }
        }
        else
        {
            return "";
        }
        return fileNameIn;
    }

    std::string get_substring(std::string strIn, int cStart, int cLength)
    {
        int strSize = (int)strIn.size();
        if(  strSize > 0 && strSize > cStart && cStart >= 0)
        {
            if( strSize > cStart+cLength && cLength > 0)
            {
                return strIn.substr(cStart,cLength);
            }
            else if( cLength!=0 )
            {
                return strIn.substr(cStart);
            }
        }
        return "";
    }

    int get_leading_space_count(std::string strIn)
    {
        if( (int)strIn.size() > 0)
        {
            int spacesCounted = 0;
            for( int i = 0; i < (int)strIn.size(); i++)
            {
                if( strIn[i]==' ')
                {
                    spacesCounted++;
                }
                else
                {
                    break;
                }
            }
            return spacesCounted;
        }
        return 0;
    }

    int get_trailing_space_count( std::string strIn)
    {
        if( (int)strIn.size() > 0)
        {
            int spacesCounted = 0;
            for( int i = (int)strIn.size()-1; i>=0; i--)
            {
                if( strIn[i]==' ')
                {
                    spacesCounted++;
                }
                else
                {
                    break;
                }
            }
            return spacesCounted;
        }
        return 0;
    }

    std::string int_to_string(int in)
    {
        std::ostringstream converter;
        converter << in;
        return converter.str();
    }

        int split_first_int(std::string &s, char separator)
    {
        size_t seppos = s.find_first_of(separator);
        if (seppos == std::string::npos)
        {
            s = "";
            return 0; // not found
        }
        int num = string_to_int(s.substr(0, seppos));
        s = s.substr(seppos+1);
        return num;
    }

    std::string split_first_string(std::string &s, char separator)
    {
        size_t seppos = s.find_first_of(separator);
        if (seppos == std::string::npos)
            return ""; // not found
        std::string outs = s.substr(0, seppos);
        s = s.substr(seppos+1);
        return outs;
    }

    std::string split_first_string(std::string& s, std::string separator)
    {
        //if(separator!=NULL)
        {
            if((int)separator.length()>=1)
            {
                size_t seppos = s.find(separator);
                if (seppos == std::string::npos)
                    return ""; // not found
                std::string outs = s.substr(0, seppos);
                s = s.substr(seppos+separator.length() );
                return outs;
            }
        }
        return "";
    }

    bool string_contains(const std::string& hay, const std::string& needle)
    {
        int haySize = (int)needle.size();
        int needleSize = (int)needle.size();
        if( (int)hay.size() > 0 && needleSize > 0 && haySize >= needleSize )
        {
            return ( hay.find(needle ) != std::string::npos );
        }
        return false;
    }

    bool string_ends(const std::string& hay, const std::string& needle)
    {
        if (hay.size() < needle.size() )
        {
            return false;
        }
        return std::equal(hay.begin() + hay.size() - needle.size(), hay.end(), needle.begin());
    }



    int string_count(std::string str, std::string needle )
    {
        int position = 0;
        int returnCount=0;
        //
        int strSize = (int)str.size();
        int needleSize = (int)needle.size();
        if( strSize > 0 && needleSize > 0 )
        {
            position = str.find( needle, position+1 );
            while ( position != (int)std::string::npos && position < strSize )
            {
                position = str.find( needle, position+needleSize );
                returnCount++;
            }
        }
        return returnCount;
    }

    std::string string_digits(std::string str)
    {
        return str;
    }

    std::string string_letters(std::string str)
    {
        return str;
    }

    std::string string_lettersdigits(std::string str)
    {
        return str;
    }

    std::string string_lower(std::string str)
    {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower );
        return str;
    }

    std::string string_repeat(std::string str,int repeatCount )
    {
        if( repeatCount > 0)
        {
            std::string strReturn = "";
            for( int i = 0; i < repeatCount ; i++)
            {
                strReturn+=str;
            }
            return strReturn;
        }
        return "";
    }

    std::string string_replace_all(std::string str, std::string substring, std::string newstr)
    {
        int newStrLen = (int)newstr.size();
        int substrLen = (int)substring.size();
        int position = str.find( substring ); // find first substring
        //
        while ( position != (int)std::string::npos )
        {
            str.replace( position, substrLen, newstr );
            if( newStrLen ==0 )
            {
                position = str.find( substring, position  );
            }
            else
            {
                position = str.find( substring, position + newStrLen );
            }
        }
        return str;
    }

    bool string_starts(const std::string& hay, const std::string& needle)
    {
        int haySize = (int)hay.size();
        int needleSize = (int)needle.size();
        if(  needleSize > 0 && haySize >= needleSize )
        {
            for( int i = 0; i < needleSize; i++)
            {
                if( hay[i]!=needle[i] )
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool string_to_bool(std::string value)
    {
        trim_string(value,' ');

        std::transform(value.begin(), value.end(), value.begin(), ::tolower);
        if (value == "true")
            return true;
        if (value == "yes")
            return true;
        if (value == "1")
            return true;
        if (value == "false")
            return false;
        if (value == "no")
            return false;
        if (value == "0")
            return false;

        return false;
    }

    int string_to_int(const std::string& s, int default_value)
    {
        int result = default_value;
        if( (int)s.size() > 0)
        {
            char *endp;

            long value = std::strtol(s.c_str(), &endp, 10);

            if (endp == s.c_str() ||  (*endp != 0) )
            {
            }
            else
            {
                result = value;
            }
        }
        return result;
    }

    float string_to_float( const std::string& s, float default_value )
    {
        //Credit: Alessandro Jacopson ( http://stackoverflow.com/users/15485/alessandro-jacopson )
        //Source: http://stackoverflow.com/a/393027
        std::istringstream i(s);
        if( (int)s.size() > 0)
        {
            float x;
            if (!(i >> x))
            {
                return default_value;
            }
            return x;
        }
        return default_value;
    }

    std::string string_upper(std::string str)
    {
        return str;
    }

    std::string trim_string(const std::string s, char c)
    {
        if (s.length() == 0)
            return "";

        unsigned int first = 0;
        unsigned int last = s.length()-1;

        while (s.at(first) == c && first < s.length()-1)
        {
            first++;
        }
        while (s.at(last) == c && last >= first && last > 0)
        {
            last--;
        }
        if (first <= last)
            return s.substr(first,last-first+1);
        return "";
    }

    std::string trim_left_inplace(std::string       s,const std::string& delimiters)
    {
        return s.erase( 0, s.find_first_not_of( delimiters ) );
    }

    std::string trim_right_inplace(std::string s, const std::string& delimiters)
    {
        return s.erase(s.find_last_not_of(delimiters) + 1);
    }

    std::string trim_string(std::string s, const std::string& delimiters)
    {
        return trim_left_inplace(trim_right_inplace(s, delimiters), delimiters);
    }

    bool wrap_string( std::string strIn,std::vector < std::string > &strVector, int lineWidth, int maxLines)
    {
        if( lineWidth <= 0)
        {
            lineWidth = 256;
        }

        strVector.clear();
        //report_message("Wrapping text [ "+strIn+" ] .");
        if( (int) strIn.size() >= lineWidth )
        {
            int prevSpacePos = 0;
            int prevSavedPos = 0;
            int spacePos = 0;
            int countedStrings = 0;
            while( (int)strIn.size() > spacePos && ( maxLines <=0 || ( maxLines > 0 && countedStrings < maxLines ) ) )
            {
                spacePos=strIn.find(" ",prevSpacePos);
                if( spacePos!=(int)std::string::npos )
                {
                    if( spacePos-prevSavedPos >= lineWidth )
                    {
                        if( prevSpacePos > prevSavedPos)
                        {
                            //report_message("Wrapped text (1).");
                            strVector.push_back( strIn.substr(prevSavedPos,prevSpacePos - prevSavedPos )  );
                            prevSavedPos = prevSpacePos;
                            prevSpacePos++;
                        }
                        else
                        {
                            //report_message("Wrapped text (2).");
                            strVector.push_back( strIn.substr(prevSavedPos,1 )  );
                            prevSpacePos = prevSavedPos+1;
                        }
                        countedStrings++;
                    }
                    else
                    {
                        //report_message("Unable to find space @"+ int_to_string(prevSpacePos)+" / "+ int_to_string(spacePos) );
                        prevSpacePos = spacePos+1;
                    }
                }
                else
                {
                    strVector.push_back( strIn.substr(prevSavedPos,lineWidth)  );
                    //report_message("Wrapped text (3)"+strIn.substr(prevSavedPos,lineWidth)+".");
                    countedStrings++;
                    prevSpacePos = prevSavedPos+lineWidth+1;
                    prevSavedPos = prevSpacePos;
                    spacePos = prevSpacePos+1;
                }
            }
            return true;
        }
        if( (int)strVector.size() ==0)
        {
            strVector.push_back( strIn );
            return false;
        }
        return false;
    }
}

