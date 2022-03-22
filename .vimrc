unlet! skip_defaults_vim
source $VIMRUNTIME/defaults.vim     
set splitbelow
set nocompatible
set termwinsize=10x0
let g:solarized_termcolors=256
set background=dark
colorscheme solarized

syntax on 

if has("gui_running")
  if has("gui_macvim")
    " MacVim
    set guifont=FiraMonoForPowerline-Medium:h14
  endif
endif

au BufNewFile,BufRead *.py,*.java,*.cpp,*.c,*.cs,*.rkt,*.h,*.html
    \ set tabstop=4 |
    \ set softtabstop=4 |
    \ set shiftwidth=4 |
    \ set textwidth=120 |
    \ set expandtab |
    \ set autoindent |
    \ set fileformat=unix |

imap jk <Esc>

vnoremap <F10> <ESC> :w <CR> :terminal ++shell g++ -O2 -o "%<" "%" && "%<" < inp <CR>
noremap <F10> <ESC> :w <CR> :terminal ++shell g++ -O2 -o "%<" "%" && "%<" < inp <CR>
inoremap <F10> <ESC> :w <CR> :terminal ++shell g++ -O2 -o "%<" "%" && "%<" < inp <CR>

noremap <F9> <ESC> :w <CR> :terminal ++shell g++ -O2 -o "%<" "%" && "%<" <CR>
inoremap <F9> <ESC> :w <CR> :terminal ++shell g++ -O2 -o "%<" "%" && "%<" <CR>
vnoremap <F9> <ESC> :w <CR> :terminal ++shell g++ -O2 -o "%<" "%" && "%<" <CR>

noremap <F8> <ESC> :w <CR> :terminal ++shell python3 "%" < inp <CR>
inoremap <F8> <ESC> :w <CR> :terminal ++shell python3 "%" < inp <CR>

noremap <F7> <ESC> :w <CR> :terminal ++shell python3 "%" <CR>
inoremap <F7> <ESC> :w <CR> :terminal ++shell python3 "%" <CR>

nnoremap <CR> :bd! <CR>
nnoremap <c-p> :browse tabnew <CR>
nnoremap <c-r> :w <CR> :so $MYVIMRC <CR>

noremap <TAB> %
call plug#begin('~/.vim/plugged')
Plug 'sheerun/vim-polyglot'
Plug 'Raimondi/delimitMate'
Plug 'vim-syntastic/syntastic'

Plug 'vim-airline/vim-airline'

Plug 'vim-airline/vim-airline-themes'

Plug 'junegunn/vim-easy-align'

Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }

Plug 'SirVer/ultisnips'
let g:UltiSnipsExpandTrigger = '<tab>'
let g:UltiSnipsJumpForwardTrigger = '<tab>'
let g:UltiSnipsJumpBackwardTrigger = '<s-tab>'

Plug 'vimsence/vimsence'
Plug 'ycm-core/YouCompleteMe'
Plug 'ervandew/supertab'

call plug#end()	

set hlsearch
set number
set autoindent
set autoread
set cin
set expandtab
set history=1000
set hlsearch
set ignorecase
set incsearch
set mousehide
set noerrorbells
set noswapfile
set number
set pastetoggle=
set shiftwidth=4
set smarttab
set tabstop=4
set vb t_vb=
"set relativenumber
 
filetype on
filetype plugin on

autocmd FileType cpp setlocal makeprg=g\+\+\ %\ \-g\ \-std\=c\+\+17\ \-Wall
autocmd FileType haskell setlocal makeprg=ghci\ %
autocmd FileType python setlocal makeprg=python3\ %
autocmd FileType sh setlocal makeprg=%
 
syntax on
 
set shellslash
set backspace=indent,eol,start
let g:ycm_clangd_binary_path = trim(system('brew --prefix llvm')).'/bin/clangd'
let g:ycm_key_list_select_completion = ['<C-n>', '<Down>']
let g:ycm_key_list_previous_completion = ['<C-p>', '<Up>']
let g:SuperTabDefaultCompletionType = '<C-n>'
let g:ycm_show_diagnostics_ui = 0

set shellslash
filetype indent on
set sw=4

" air-line
let g:airline_powerline_fonts = 1
let g:airline_theme = 'jellybeans'
let g:airline#extensions#tabline#enabled = 1

if !exists('g:airline_symbols')
    let g:airline_symbols = {}
endif

" unicode symbols
let g:airline_left_sep = '»'
let g:airline_left_sep = '▶'
let g:airline_right_sep = '«'
let g:airline_right_sep = '◀'
let g:airline_symbols.linenr = '␊'
let g:airline_symbols.linenr = '␤'
let g:airline_symbols.linenr = '¶'
let g:airline_symbols.branch = '⎇'
let g:airline_symbols.paste = 'ρ'
let g:airline_symbols.paste = 'Þ'
let g:airline_symbols.paste = '∥'
let g:airline_symbols.whitespace = 'Ξ'

" airline symbols
let g:airline_left_sep = ''
let g:airline_left_alt_sep = ''
let g:airline_right_sep = ''
let g:airline_right_alt_sep = ''
let g:airline_symbols.branch = ''
let g:airline_symbols.readonly = ''
let g:airline_symbols.linenr = ''

