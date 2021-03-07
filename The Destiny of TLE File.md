## Destiny of TLE files, a play
					         A play in one act











Character list 
CHARACTER NAME: Blake, an adolescent boy with a passion on coding 
CHARACTER NAME: The Previous Solution, the first program Blake wrote
CHARACTER NAME: The O(n ^ 2) Solution, the second program Blake wrote
CHARACTER NAME: Prefix-Sum Solution, the third program Blake wrote
CHARACTER NAME: The judge, judge on LeetCode, a coding website
CHARACTER NAME: Fish, a pet fish 
Background knowledge: LeetCode is a website that hosts challenging coding problems. While Blake is trying to solve one of the problems, he runs into an issue called “Time Limit Exceeded”, where a program cannot give the solution within the given time. 
*Time complexity is the way that a program runs.
A computer typically can run 1e8 times per second meaning 108, the greater the time complexity, the slower the program. Regarding the problem that Blake was trying to solve, the worst case n is equal to 1e7, that means O(n2) will cause Time Limit Exceeded because 1e72 > 1e8. The maximum time complexity is O(n logn) which is 1e7 * log base 2 1e7 which is less than 1e8.
Github is the website where users can submit their programs for others to read.
Synopsis: Blake is doing some coding problems. Blake first codes his original solution O(n3), who gets Time Limit Exceeded. Blake later on codes a second solution who has a time complexity of O(n2). The new solution shows great prejudice toward the old solution. Blake deletes the original solution and submits the new solution. It turns out that even the new solution fails the test. The O(n2) Solution, knowing his fate of getting deleted, wants to escape its destiny. A fish helps him and gets him out of the folder but the fish ends up suffocating. The O(n2) fails to send himself on to Github because Blake just walks in. Finally Blake codes another solution that uses prefix sum and that solution is able to pass the test. The O(n2) Solution learns the lesson not to prejudice over others but ultimately ends up in the trash bin.
Scene 1: Blake’s Computer
A small bedroom that features a workstation with a bed in the corner, and a computer on a desk. Outside the window, the sun shines right on the face of Blake, a teenager who sits by the computer desk, crouching over the computer. At this moment, Blake has just created a cpp file. On the keyboard, the boy types the file name, DFS O(n2). Blake feels confident that he is ready to tackle the problem on Leetcode.

Blake
I got it! I can reduce the time complexity by calculating the sum of the subset while I enumerate the right endpoint of the array! If I do that, I will have a time complexity* of O(n2).
				(cracking his fingers and smiling)

					The O(n2) Solution
What is that?
			(quickly examining a file in the computer)
	
The Previous Solution
Are you talking to me? I am the previous solution that our creator coded.
(With fear, eyes surveying the new added file.)

					The O(n2) Solution
Why so scared? You sounded shaking.

The Previous Solution
You are probably here to replace me. I am not good enough because I got a Time Limit Exceeded and can’t solve the problem on LeetCode in time.  My creator is going to move me to the trash bin!
					The O(n2) Solution(cont’d)
 What problem on LeetCode?
The Previous Solution 
Obtaining the maximum possible sum in a subset of a given array!
The O(n2) Solution
Oh! That is the problem that I am solving as well.
(Giggling and looking down at the Previous Solution)
You are enumerating the left endpoint, then the right endpoint, and within that, you enumerate everything inside the gap again. I see that your time complexity is O(n3). No wonder why you cannot solve the problem in time. It sounds right to me that you belong to the trash bin if you cannot even promptly handle a simple task when n is greater than a hundred.
The Previous Solution 
It is not my fault that my time complexity is O(n3). I was made this way. I have no choice. Just like you...you don’t have a choice deciding your time complexity.

The O(n2) Solution
Maybe it’s true that it is not your fault that your Time Complexity is O(n3). Still, there is no room for you here. I know it is tragic, but this is the lives of us programs. When you are useless, you get ditched. That is how the world goes.
(Seeing that the O(n2) Solution running well and passing 
the sample test case on LeetCode, Blake hits one button on the 
keyboard and moves The Previous Solution to the trash bin.)
			
		The O(n2) Solution
Hahaha! A solution with O(n3) Time Complexity only belongs to the trash bin!
(While laughing hard, the O(n2) Solution sees from the 
corner of its eyes a fish swimming in a fish jar.) 
					The O(n2) Solution (cont’d)
OMG! You have been eavesdropping all the way?
Fish
I sure am. And you know what? The Previous Solution acted once like you.
The O(n2) Solution 
Don’t compare me with a solution that has a time complexity of O(n3)! It’s humiliating.
Fish
You guys behave the same way. Learn to appreciate others, and understand others even though they might not be as good as you in something. Act kindly, man!
	(With confidence, Blake submits the The O(n2) Solution file onto LeetCode.)


					Scene 2: Online
						Judge
Hello, file! I am your judge today and I will be judging your validity to this problem.
The O(n2) Solution
Ok, I am ready. Let’s get it started!
			(The Judge gives the O(n2) Solution some sample test cases,
 and the new file passes them with ease.)
						Judge
Don’t be happy too early. Here comes the last subtask.
		(Jumping up and down, the O(n2) Solution eagerly looks forward 
  to the moment when the word “accepted’ in green shows up.)
The O(n2) Solution
Easy peasy, just too easy, I can do this al--
						
					Judge (Cont’d)
Time Limit Exceeded!!!
					The O(n2) Solution
What? How can I fail? Must be that I did not try hard enough, let us do it again

(The O(n2) Solution’s eyes open wider, and his face is shocked. Blake looks down. Blake resubmits The O(n2) Solution again.)
Judge
Time Limit Exceeded!!!
The O(n2) Solution
How? It must be that I didn’t try hard enough. Give me one more chance, give me one more chance!!!
Judge
It is not because you didn’t try hard, your time complexity is O(n2), but this last subtask n is smaller than or equal to 1e7. It is not your fault, a program that passes this problem will have a time complexity of at least O(nlogn)

(The O(n2) solution suddenly feels pale and cold. Thinking back to what happened to the previous solution.)
The O(n ^ 2) Solution
Please give me one more second or something, I can surely pass this problem, I don’t wanna go to the trash bin.
						





Judge(cont’d)
Very sorry pal, it is not because I don’t want to help you, I am made this way, I cannot change how I behave just like how you cannot change your time complexity. I judge based on the .out file that my creator uploaded. I don’t have the power to change the .out file or make false judgement. I also live in pain, everyday, every second, I see all kinds of different files of solutions fail, not just cpp files, but other files such as java files, py files etc. In fact, most failed, only few can pass the test. If I have the power to change the .out file, time limit or the memory limit, I would’ve changed them and saved thousands of solutions
					The O(n2) Solution
Please, just give me advice, wise judge, what should I do to escape my fate in the trash bin.
Judge
Try to escape your folder, therefore, make an account on github.com, therefore, upload yourself as a cpp file there and make sure nobody knows the password. Then, nobody can even try to delete you and you will forever be in your repository on github.com

						Blake
How can I further improve my time complexity? I must be missing something.
						Judge
Looks like your creator is logging out of LeetCode, good luck.
(Blake logs out of LeetCode, and goes to get some rest.)
				

Scene 3: Blake’s Computer(cont’d)
The O(n2) Solution
“I will escape my fate, I will not end up the same as the previous solution, I will escape this folder, I will upload myself onto github.com.”

(The O(n2) Solution struggles to escape the folder.)
The O(n2) Solution
Anyone, please help!
(then, he sees the fish, beside the computer, leap out of the fish jar, and crawl to the mouse.)
		Fish
I am here to help!!!
					The O(n2) Solution(cont’d)
Oh thank you my dear friend, I don’t know how I can repay you for such kindness
						Fish
Get ready, I am moving you out of the folder.
				
(With a drag, the O(n2) Solution is out of the folder. His smile is even brighter than before, but the small goldfish, suffocating and hungry for water, is on the verge of death.)
					


The O(n2) Solution(cont’d)
Oh, dear fish, why did you risk your life to save me?
						Fish
Everyday, I see so many failed solutions deleted. Rather than sitting at the jar, I decide to make a difference. I also seek freedom. I came from the ocean, but ended up in this tiny water jar. It is a prison. I am too far away from freedom. When you’re free, live a good life, for me, please!
(fish dies)
					The O(n2) Solution
Thank you fish, I will live well. I will forever remember your kindness. I will learn to be kind to others.

(The O(n2) Solution quickly opens up google chrome, creates an account on Github.com, and is ready to upload himself onto Github.com.)
					The O(n2) Solution
I will be free!!!!

(Just at this moment, Blake walks into his room, ready to code once again.)
						Blake
Oh damn, my goldfish jumped out again, gotta get a new one the next day I guess. Why is Github open on my computer? Doesn’t matter, maybe I just forgot to close it.
					
(Blake closes Github.com, and puts The O(n2) Solution back into the folder.)
					The O(n2) Solution
Why not just a bit more time, all that the fish did now is in vain. I could’ve done that quicker so close, yet so far.
	
						
Blake(cont’d)
Alright, I got it, if I use Prefix Sum to store all the sum of every subset starting at position zero and ending in various points, all that I have to do later is to enumerate through all the points while also storing the minimum sum in all prefixes. Therefore, I can get the largest sum possible ending in each position as its own sum subtract by the minimum prefix that appeared before. This works because the smaller the minimum prefix, the bigger the whole sum. This should be able to solve this problem in linear time!!!

					The O(n2) Solution
Noooo, what is then my reason of existence?

(Blake quickly codes the new solution, and names it the prefix sum solution. The new solution, once again, just like The O(n2) Solution, is young and full of spirit, but with the same prejudice and defiance.)
					Prefix sum Solution
It is good to feel alive sometimes.
				
(The Prefix sum Solution turns his eyes and looks at The O(n2) Solution.)
					Prefix sum solution
Haha, you must be the previous solution that the creator had coded, must be too slow, I am here to replace you.
The O(n2) Solution
You know I was once like you. I also felt that I was superior to all the other solutions before. In truth, I don’t have the ability to change my own time complexity, just like how the judge on LeetCode doesn’t have the ability to make false judgement nor change the .out file that his creator submitted. Just like how the fish doesn’t have the power to get back to the ocean from the fish jar, we all have something that we wish to change but we cannot. That is fate. It may be that you are faster than me, however, I might be better than you in some other aspects. What aspect right now I don’t know, but I am certain that there is. We need to help each other, therefore changing our fate together.
					Prefix sum Solution
Well, what is the reason that I have to help you if you cannot even solve this problem in linear time? In fact, stop acting like you are my mentor because you are older, you are not even worthy enough, a program with a time complexity of O(n2). Get to where you deserve, go to the trash bin!
					The O(n2) Solution
You might not understand me now but, you will one day, you will.
						Blake
Lets see, this should pass.
						
(Blake submits the Prefix sum solution to LeetCode.)
					Prefix sum Solution
int n is 1e7, easy!!!	
			
The Prefix sum solution passes the problem with ease. The O(n2) Solution looks at the green Accepted, that the Prefix sum Solution obtained. He really hopes that it is himself who got the green Accepted.
The O(n2) Solution
Oh, how beautiful, all that I hope now is that I can get this myself, but I don’t think that day is ever going to happen. I accept my fate.
						Blake
Alright, finally passed this problem, ok this file can go the trash, and free some storage.
						
(Without hesitation once again, Blake drags The O(n2) Solution into the trash bin. The O(n ^ 2) Solution is not scared anymore. He accepts his fate, and he is glad to ever exist in this world, even the time is not long. He is also glad that he left a mark in this world. When he was submitted to LeetCode, he felt glad about what he had accomplished even though the result was not Accepted. 
(At the trash bin, the O(n2) Solution sees the O(n3) Solution)
					The O(n2) Solution
Oh dear friend, sorry for what I said a while ago, I didn’t know anything at that time. Please forgive me.
					The O(n3) Solution
It's fine, we all make mistakes, this is where we end up, let's face it together.

