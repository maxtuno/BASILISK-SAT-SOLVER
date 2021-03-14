# BASILISK SAT SOLVER

Simple and efficient pure CDCL algorithm for educational purposes.

	Licence BSD

	Copyright (c) 2021 Oscar Riveros. all rights reserved. oscar.riveros@peqnp.science

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.


	sgen4 -n 50 -sat > sat.cnf            
	time ./basilisk-sat-solver sat.cnf --all
	c reading 1280 characters from sat.cnf
	c 0     
	SAT
	1 -2 -3 -4 -5 6 7 8 9 -10 11 -12 -13 -14 -15 -16 -17 18 -19 20 21 22 23 24 -25 -26 27 28 -29 -30 -31 -32 -33 34 35 -36 -37 -38 39 -40 41 -42 43 44 45 -46 47 -48 49 50 0
	c 0     
	SAT
	1 -2 -3 -4 -5 6 7 8 -9 -10 11 -12 -13 -14 -15 -16 17 -18 19 20 21 22 23 24 -25 -26 27 28 -29 -30 -31 -32 33 34 -35 -36 -37 -38 39 40 41 -42 43 44 45 -46 47 -48 -49 50 0
	c 0     
	SAT
	1 -2 -3 -4 5 6 7 -8 -9 -10 11 -12 13 -14 -15 -16 17 18 -19 20 21 22 -23 24 -25 -26 27 28 -29 -30 31 -32 33 34 35 -36 -37 -38 -39 -40 41 42 43 44 45 -46 -47 -48 -49 50 0
	c 0     
	SAT
	-1 -2 -3 -4 5 6 -7 8 -9 -10 -11 -12 -13 -14 -15 16 17 18 19 20 21 -22 -23 24 -25 -26 27 -28 -29 -30 31 -32 -33 34 35 -36 -37 38 -39 -40 -41 -42 43 44 45 -46 47 48 49 50 0
	c 15    
	UNSAT
	./basilisk-sat-solver sat.cnf --all  0.33s user 0.00s system 99% cpu 0.336 total

	% sgen4 -n 50 -unsat > unsat.cnf          
	% time ./basilisk-sat-solver unsat.cnf --drat-proof > unsat.proof
	./basilisk-sat-solver unsat.cnf --drat-proof > unsat.proof  243.79s user 1.18s system 99% cpu 4:06.36 total
	
	% drat-trim unsat.cnf unsat.proof 
	c parsing input formula with 53 variables and 116 clauses
	c finished parsing
	c detected empty clause; start verification via backward checking
	c 116 of 116 clauses in core                            
	c 74672 of 80570 lemmas in core using 1128394 resolution steps
	c 0 RAT lemmas in core; 46577 redundant literals in core lemmas
	s VERIFIED
	c verification time: 4.532 seconds