/* Copyright 2014 the SumatraPDF project authors (see AUTHORS file).
   License: Simplified BSD (see COPYING.BSD) */

#ifndef SplitterWnd_h
#define SplitterWnd_h

struct SplitterWnd;

// Live versions indicate that the owner will re-layout windows in the callback
// In non-live version we'll draw an indicator of where the splitter will be
// at the end of resize and the owner only re-layouts when callback is called
// with 'done' set to true
enum SplitterType {
    SplitterHoriz,
    SplitterHorizLive,
    SplitterVert,
    SplitterVertLive
};

// called when user drags the splitter ('done' is false) and when drag is finished ('done' is
// true). the owner can constrain splitter by using current cursor
// position and returning false if it's not allowed to go there
typedef bool (*SplitterCallback)(void *ctx, bool done);

void           RegisterSplitterWndClass();
SplitterWnd *  CreateSplitter(HWND parent, SplitterType type, void *ctx, SplitterCallback cb);
HWND           GetHwnd(SplitterWnd *);
void           SetBgCol(SplitterWnd *, COLORREF);

#endif