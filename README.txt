README.txt

Readme file associated with the project christmasCard2011

Conor Stefanini, 25 May 2015

----

christmasCard2011
	Purpose
		This project is a Christmas Card
		It's a very simple program that uses a graphics library
			to display a moving Christmas Card
	Context
		This project was written sometime from September to
			December 2011
		It was my first college assignment, written for
			Bryan Duggan's Programming class, taught to 
			DT211 first years
	Tools
		This project is written in C and uses the Allegro library
			for graphics
		Allegro 4.4.2
		The project was originally written with Visual Studio 2011,
			it's currently being developed with GCC on
			Linux Mint 17
	
	Conor Stefanini, 25 May 2015

----

Usage
	The escape key and the 'Q' key ends the program
	The 'Z' key freezes the screen momentarily and fills it
		with a random colour
	
	Conor Stefanini, 26 May 2015

----

Change Log




	2015-05-26
		General Details
			Created "christmasCard2011.c",
				Got the two main functions in
			Wrote the "makefile"
		Usage
			The escape key and the q key ends the program
			The z key freezes the screen momentarily and 
				fills it with a random colour
		Changes to Source
			Created "christmasCard2011.c" and copied in
				drawXmasBalls, and drawSnowFlake
				Modified the two functions slightly
				Set up the Z key to freeze the screen
				Set up the programs main screen to run
			Wrote the "makefile", works when Allegro 4.4.2 is
				installed
			Wrote "tester.c" to test logic of functions in
				christmasCard2011.c
			Moved all old files and tester.c to the directory
				"oldVersions"
		To Do
			Fix the comments in drawXmasBall (remove old version)
			Fix comments in both functions
			Continue with implementing old functions
			Do little movie type things
			Maybe screen buttons instead of keyboard input
			Maybe start using tabs instead of spaces, I like
				4 tab width for comments
		
		Conor Stefanini, 26 May 2015


	2015-05-25_2
		General Details
			No change to actual source files
		Changes to Source
			Changed this README.txt file to look better when
				viewed with tab spacing of 8, as github
				displays it
		Additional
			Usage, and To Do sections are the same as previous
				entry
			I'm going to use a this version of titles from now on:
				"2015-05-25_2" == "Year-Month-Date_Version", 
				this is the second commit / upload today, so
				the date is underscored as the second version
			I'm going to consider including the time with date
				signatures / changelog entries
		
		Conor Stefanini, 25 May 2015


	2015-05-25
		General Details
			First version of this git project
			First step in to git projects in general
			I'm uploading these versions first so that I can
				build on them through git (seems like the
				purpose / a strong point of git)
			These are each version of my Winter 2011 programming
				assignment done for Bryan Duggan's class
				in DIT, course DT211
		Usage
			The Escape key ends each version of the program
			The keys q, w, e, r, t, etc. and a, s, d, f, g, etc.
				do some stuff
		Changes to Source
			Fixed minor issues in source code (void main(),
				return;, etc.)
			Created this readme file
			Created an empty makefile (I'm not going to write it
				for this version)
		To Do
			Read a changelog style guide
				Set this file up as markdown (maybe)
			Possibly add version numbers
			Source
				Combine the three files in to one
				Write a makefile
				Fix dependencies
					Move the allegro libraries to the
						project folder
				Set up a folder structure (lib, src, bin, or
					dependencies, source, executables,
					or something along those lines)
				Fix the style of the final C file
				Fix all unused variables, etc.
				Add comments
				Optimise (use less variables, etc.)
		
		Conor Stefanini, 25 May 2015

----

Additional
	This file is definitely going to change in structure and purpose
	This is my first attempt at a version control system and I can already
		tell that version control does some of the things I'm trying
		to do through this plain text file
	Either way, the projects that I put on github are going to be
		documented in some way, even if it's inappropriate or
		inefficient, I'll learn a better way in time and practise
	
	Conor Stefanini, 25 May 2015

----




