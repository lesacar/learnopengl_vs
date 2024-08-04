#pragma once

class VSync
{
public:
    VSync(bool vsync);
    void set(bool vsync);
    bool get();

private:
    bool Vsync;
};