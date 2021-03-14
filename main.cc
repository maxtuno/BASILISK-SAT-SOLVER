/*
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
*/

#include <cmath>
#include <basilisk/solver.hh>

int main(int argc, char *argv[]) {
    using T = int;

    auto enumerate = false;
    std::string path;

    basilisk::solver<T> solver;

    for (auto i = 1; i < argc; ++i) {
        if (!std::strcmp(argv[i], "--all")) {
            enumerate = true;
        } else if (!std::strcmp(argv[i], "--drat-proof")) {
            solver.drat_proof = true;
        } else {
            path = argv[i];
        }
    }
    if (path.empty()) {
        printf("Usage: %s [--all | --drat-proof] <dimacs-format-file.cnf>\n", argv[0]);
        std::exit(EXIT_FAILURE);
    }
    solver.load_cnf(path);
    for (;;) {
        T status = solver.solve();
        if (status != 0) {
            printf("\n%sSAT\n", status > 0 ? "" : "UN");
            if (status > 0) {
                for (auto x = 1; x <= solver.number_of_variables; ++x) {
                    if (solver.model[std::abs(x)]) {
                        std::cout << solver.model[std::abs(x)] << " ";
                    }
                }
                std::cout << "0" << std::endl;
            }
            if (enumerate && status > 0) {
                solver.trail_head = 0;
                std::vector<T> literals;
                for (T x = 1; x <= solver.number_of_variables; x++) {
                    if (solver.model[std::abs(x)]) {
                        literals.push_back(-solver.model[std::abs(x)]);
                    }
                }
                solver.add_clause(literals);
                continue;
            } else {
                return EXIT_SUCCESS;
            }
        }
    }
}
