# Librarian
The idea is to split a database across multiple machines. Therefor lowering the need for high-performance hardware. Because queries will be done on smaller sub-sets of the whole data set. But by joining the results of each sub-set into a single result, the query will include any matching data from the whole database.

## Concept
In the basis all queries (simple and complex) start by doing a matching records on a single table and match that agains an other dataset, sorting it beforehand or afterwards. Therefor an advanced query engine can be build upon a set of interfaces that allows just that.

## Steps

- **First step:**
Will be making a simple engines that is able to store the data in files, and make use of some indexes to speed-up the searching and sorting of the data.

- **Second step**:
Will be making a master side that is able to inquery on multiple instances for selections, and can add new data distributes across the slaves.

- **Third step:**
Making somekind of SQL, supporting the logic to make join queries, grouping data etc, using the interface layer so it's not depending on knowledge of any storge engine that is implimented.
