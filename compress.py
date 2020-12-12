from enum import Enum

class State(Enum):
  CODE = 1
  C_COMMENT = 2
  CPP_COMMENT = 3
  STRING_LITERAL = 4

def remove_garbage(text):
  result = []
  prev = ''
  prevprev = ''
  state = State.CODE

  for ch in text:
    if state == State.C_COMMENT:
      if prevprev != '\\' and prev == '*' and ch == '/':
        state = State.CODE
        prevprev = prev = ''
      elif ch == '\n':
        result.append('\n')
        prevprev = prev = ''
      else:
        prevprev, prev = prev, ch
      continue

    # Skip to the end of the line (C++ style comment)
    if state == State.CPP_COMMENT:
      if ch == '\n':  # End comment
        state = State.CODE
        result.append('\n')
        prevprev = prev = ''
      continue

    if state == State.STRING_LITERAL:
      if prev != '\\' and ch == '"':
        state = State.CODE
      result.append(prev)
      prevprev, prev = prev, ch
      continue

    if prevprev != '\\' and prev == '/' and ch == '*':
      state = State.C_COMMENT
      prevprev = prev = ''
      continue

    if prevprev != '\\' and prev == '/' and ch == '/':
      state = State.CPP_COMMENT
      prevprev = prev = ''
      continue

    if prev:
      if prev != ' ' or ch != ' ':
        result.append(prev)

    if ch == '"':
      state = State.STRING_LITERAL
    prevprev, prev = prev, ch

  if prev:
    result.append(prev)
  return ''.join(result)

if __name__ == '__main__':
  p = "C:\\Users\\denjo\\Desktop\\ABC\\library\\unused\\a.cpp"
  with open(p, "r", encoding='utf-8') as f:
    content = f.read()
    compressed = remove_garbage(content)
  with open(p, "w", encoding='utf-8') as f:
    f.write(compressed) 