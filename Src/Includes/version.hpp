/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-florent.canales
** File description:
** version
*/

#ifdef __linux__
        const char NEW_LINE = '\n';
    #elif _WIN32
        const char NEW_LINE = '\r\n';
        #include <Windows.h>
    #endif