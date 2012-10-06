//////////////////////////////////////////////////////////////////////////
// Copyright 2012 Peter Atechian (Retep998)                             //
//////////////////////////////////////////////////////////////////////////
// This file is part of the NoLifeStory project.                        //
//                                                                      //
// NoLifeStory is free software: you can redistribute it and/or modify  //
// it under the terms of the GNU General Public License as published by //
// the Free Software Foundation, either version 3 of the License, or    //
// (at your option) any later version.                                  //
//                                                                      //
// NoLifeStory is distributed in the hope that it will be useful,       //
// but WITHOUT ANY WARRANTY; without even the implied warranty of       //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        //
// GNU General Public License for more details.                         //
//                                                                      //
// You should have received a copy of the GNU General Public License    //
// along with NoLifeStory.  If not, see <http://www.gnu.org/licenses/>. //
//////////////////////////////////////////////////////////////////////////
#include <string>
#include <cstdint>
namespace NL {
    class String;
    class Sprite;
    class Sound;
    class Node;
    class File;
    class String {
    public:
        uint16_t Size() const;
        const char * Data() const;
        operator std::string() const;
    private:
        void * d;
        friend Node;
    };
    class Sprite {
    };
    class Sound {
    };
    class Node {
    public:
        Node begin() const;
        Node end() const;
        Node operator*() const;
        Node operator++();
        Node operator++(int);
        bool operator==(Node) const;
        bool operator!=(Node) const;
        Node operator[](std::string) const;
        Node operator[](String) const;
        Node operator[](char *) const;
        Node operator[](const char *) const;
        Node Get(const char *, size_t) const;
        int32_t X() const;
        String Name() const;
        size_t Num() const;
        enum class Type : uint16_t {
            none = 0,
            ireal = 1,
            dreal = 2,
            string = 3,
            vector = 4,
            sprite = 5,
            sound = 6,
        };
        Type T() const;
    private:
        struct Data;
        static Node Construct(Data *, File *);
        Data * d;
        File * f;
        friend File;
    };
    class File {
    public:
        File(std::string);
        ~File();
        Node Base();
    private:
        void * file;
        void * map;
        size_t size;
        void * base;
        struct Header;
        Header * head;
        uint64_t * stable;
        Node::Data * ntable;
        friend Node;
    };
}