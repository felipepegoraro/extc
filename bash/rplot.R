require('tidyverse')

df <- read_delim('./file.csv',
								 delim=",", show_col_types = FALSE)

newdf <- df %>% 
  mutate(percent = 100 * count/sum(count), 
         others  = 
            ifelse(percent < 5 | name == "makefile", count,
            ifelse(NA)))

perc_others <- sum(newdf$others, na.rm=TRUE)/sum(newdf$count)

gp1 <- newdf %>% 
  filter(is.na(others)) %>% 
  ggplot(aes(x = name, y = count)) +
      geom_bar(aes(fill=percent),
          stat = "identity",
          width = .5,
          position="dodge") +
      labs(x="language", y="lines", 
           subtitle=sprintf("others: %.5f%%", perc_others))

gp1
