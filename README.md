SDLMac
======

SDLMac(ros) - a bunch of macros for lazy developpers

- What's this?

First off all, Hey, thanks for checking out! Next, this is a header file with a bunch of macros that removes most of SDLs setup with a few macros and gets you right into the action in less than 1 minute! (Approx. Value)

- Nice! So ... How do I install it?

Well, It's really easy, You just include the file in your SDL Project (SDL & SDL_Image headers must be included and libs linked) and you're ready to go!

- Now what?

Yeh now ... You just put in __macVars__ (variables necessary for mac to run) with your variables then you init SDL with a macQuit(SDL_Init(SDL_INIT_EVERYTHING)); (quits SDL if value fed is 1 - Literally an if()), then you create a window with
macCreateWindow("Hello World!", 480, 480, SDL_WINDOW_SHOWN, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); (arguments being: title, width, height, windowflags, rendererflags), next you load in a texture macLoadTex(path) and you draw it in a loop with macClearWindow(), macDrawTex(macTex(0), 100, 100, 90) (macTex(i) returns i-th loaded texture, 100 & 100 being X & Y and 90 being angle in degrees), macUpdateWindow() and here ye go!

- Oh man, I've been waiting for this for like EVAR! What can I do to help?

Just go ahead and make it better, be sure to let me know if you made any nice modifications, I'll be sure to update that source

- Could i get the source?

Download the example here ... https://db.tt/9dvf4AWN


- Sweet! Thanks!

Just a notice, use it as you want, just be sure to keep a copy of the original src when distributing
